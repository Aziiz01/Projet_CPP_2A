<?php
    class panier{
        private $id=0;
        private $nom_prod=null;
        private $prix=0;
        private $qte=0;

        public function construct($nom_prod,$qte,$prix)
        {
            $this->nom_prod=$nom_prod;
            $this->qte=$qte;
            $this->prix=$prix;
        }
        /////////////////////////////////
        public function get_id()
        {
            return $this->id;
        }
        public function get_nom_prod()
        {
            return $this->nom_prod;
        }
        public function get_qte()
        {
            return $this->qte;
        }
        public function get_prix()
        {
            return $this->prix;
        }
        ////////////////////////////////
        public function set_nom_prod($nom_prod)
        {
            $this->nom_prod=$nom_prod;
        }
        public function set_qte($qte)
        {
            $this->qte=$qte;
        }
        public function set_prix($prix)
        {
            $this->prix=$prix;
        }
       
    }
?>