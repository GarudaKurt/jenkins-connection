pipeline {
    agent any

    options {
        timestamps()
        buildDiscarder(logRotator(numToKeepStr: '20'))
    }

    environment {
        BUILD_DIR = 'build'
    }

    stages {

        stage('Checkout') {
            steps {
                checkout scm
            }
        }

        stage('Configure') {
            steps {
                sh '''
                    cmake -S . -B $BUILD_DIR
                '''
            }
        }

        stage('Build') {
            steps {
                sh '''
                    cmake --build $BUILD_DIR
                '''
            }
        }

        stage('Test') {
            steps {
                sh '''
                    ./$BUILD_DIR/main
                '''
            }
        }
    }

    post {
        success {
            echo 'Build and tests passed.'
        }
        failure {
            echo 'Build or tests failed. Check console output above.'
        }
        always {
            cleanWs()
        }
    }
}