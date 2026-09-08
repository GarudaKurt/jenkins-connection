pipeline {
    agent {
        label "ShapeClasses-Machine"
        docker {
            image 'gcc:13'
        }
    }

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

	stage('Check Agent') {
	    steps { 
                sh ''
                    echo "===== AGENT INFORMATION ====="
		    echo "User: $whoami"
		    echo "OS:"
		    cat /etc/os-release
		    echo "Java:"
		    java --version
		''
	    }
	}

        stage('Install Tools') {
            steps {
                sh '''
                    apt-get update -qq
                    apt-get install -y -qq cmake
                '''
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
