pipeline {
    agent { 
        node {
            label 'docker-agent-my-complete'
        }
    }
    triggers {
        pollSCM '*/5 * * * *'
    }
    stages {
        stage('Build') {
            steps {
                echo "Building.."
                sh '''
                mkdir build && cd build
                cmake ..
                cmake --build .
                '''
            }
        }
        stage('Test') {
            steps {
                echo "Testing.."
                sh '''
                cd build
                ./runUnitTests --gtest_output=xml:build/test-results/results.xml
                '''
            }
        }
        stage('Deliver') {
            when {
                expression {
                    return currentBuild.result == null || currentBuild.result == 'SUCCESS'
                }
            }
            steps {
                echo 'Deliver....'
                sh '''
                cd build
                ./SensorNetwork
                '''
            }
        }
    }
    post {
        always {
            junit '**/build/test-results/*.xml'
        }
        failure {
            echo 'Build failed. Check the test results.'
        }
    }
}
