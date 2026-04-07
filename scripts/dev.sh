#!/bin/bash

# DSA Practice - Development Script
# Helps with running common tasks

usage() {
  echo "Usage: ./scripts/dev.sh [command]"
  echo ""
  echo "Commands:"
  echo "  test              Run tests"
  echo "  test:watch        Run tests in watch mode"
  echo "  test:coverage     Run tests with coverage report"
  echo "  lint              Lint TypeScript files"
  echo "  format            Format code with Prettier"
  echo "  clean             Remove build artifacts"
  echo "  help              Show this help message"
}

case "$1" in
  test)
    npm test
    ;;
  test:watch)
    npm run test:watch
    ;;
  test:coverage)
    npm test -- --coverage
    ;;
  lint)
    npm run lint
    ;;
  format)
    npm run format
    ;;
  clean)
    rm -rf dist/ coverage/ .nyc_output/
    echo "Cleaned build artifacts"
    ;;
  help|"")
    usage
    ;;
  *)
    echo "Unknown command: $1"
    usage
    exit 1
    ;;
esac
