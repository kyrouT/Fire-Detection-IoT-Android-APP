<template>
  <base-layout :page-title="title" page-default-back-link="/homepage">
    <iframe  width="100%" height="260" style="border: 1px solid #cccccc; margin-bottom:20px" :src="diagramFull"></iframe>
  </base-layout>
  
</template>

<script>
export default {
    data() {
        return {
            dia1: "https://thingspeak.com/channels/1642633/charts/",
            dia2: "?bgcolor=%23ffffff&color=%23d62020&dynamic=true&results=60&type=line&update=15",
            title: ""
        }
    },
    computed: {
        diagramFull() {
            return this.dia1 + this.$route.params.id + this.dia2;
        }
    },
    methods: {
        getTitle() {
            if (this.$route.params.id == 1) {
                this.title = "Temperature";
                console.log(this.title);
            }
            else if(this.$route.params.id == 2) {
                this.title = "Humidity";
            }
            else if(this.$route.params.id == 3) {
                this.title = "Wind";
            }
            else if(this.$route.params.id == 4) {
                this.title = "Smoke";
            }        
        }
    },
    mounted() {
        this.getTitle();
    }
}
</script>

<style>

</style>