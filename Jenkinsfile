pipeline {
    agent any

    options {
        timestamps()
        buildDiscarder(logRotator(numToKeepStr: '10'))
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
                sh """
                    cmake -S . -B %BUILD_DIR% -G "MinGW Makefiles" -DCMAKE_CXX_COMPILER=C:/msys64/ucrt64/bin/g++.exe
                """
            }
        }

        stage('Build') {
            steps {
                sh """
                    cmake --build %BUILD_DIR%
                """
            }
        }

        stage('Test') {
            steps {
                sh """
                    %BUILD_DIR%\\main.exe
                """
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