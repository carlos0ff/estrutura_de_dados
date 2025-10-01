<?php

/**
 * Recursão - Implementação em PHP
 * Autor: Seu Nome
 * Data: 2025-09-29
 */

class Recurso {
    public function demonstrar() {
        echo "Demonstração de Recursão em PHP\n";
        echo "================================\n\n";
        $this->exemploBasico();
    }
    
    private function exemploBasico() {
        echo "Implemente aqui a demonstração de Recursão\n";
    }
}

// Execução
if (PHP_SAPI === 'cli') {
    $recurso = new Recurso();
    $recurso->demonstrar();
}