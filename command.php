<?php
    class command{
        private $id=0;
        private $date=null;
        private $prix=0;
        private $adresse=null;
        private $elements="";

        public function construct($elements,$date,$prix,$adresse)
        {
            $this->elements=$elements;
            $this->date=$date;
            $this->prix=$prix;
            $this->adresse=$adresse;
        }
        /////////////////////////////////
        public function get_id()
        {
            return $this->id;
        }
        public function get_elements()
        {
            return $this->elements;
        }
        public function get_date()
        {
            return $this->date;
        }
        public function get_prix()
        {
            return $this->prix;
        }
        public function get_adresse()
        {
            return $this->adresse;
        }
        ////////////////////////////////
        public function set_elements($elements)
        {
            $this->elements=$elements;
        }
        public function set_date($date)
        {
            $this->date=$date;
        }
        public function set_prix($prix)
        {
            $this->prix=$prix;
        }
        public function set_adresse($adresse)
        {
            $this->adresse=$adresse;
        }
       
    }
?>