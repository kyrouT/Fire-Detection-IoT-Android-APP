<template>
  <base-layout pageTitle="Firduino">
        <template v-slot:actions-end>
            <router-link :to="{path: '/sensors/map'}">
                <ion-button>
                <ion-icon slot="icon-only"  :icon="mapOutline"></ion-icon>
            </ion-button>
            </router-link>
            <router-link :to="{path: '/sensors'}">
                <ion-button>
                <ion-icon slot="icon-only"  :icon="locateOutline"></ion-icon>
            </ion-button>
            </router-link>
            <ion-button  @click="openModal">
                <ion-icon slot="icon-only"  :icon="helpCircle"></ion-icon>
            </ion-button>
        </template>
        <ion-card class="ok" :color="colorHome" router-link="/sensors">
            <ion-card-header>
            <h1>{{messageHome}}</h1>
            </ion-card-header>
            <ion-card-content>
            <h2>{{notificationMessage}}</h2> 
            </ion-card-content>
              <ion-row class="ion-justify-content-center" >
                   <ion-img style="width:100px"  src="https://cdn-icons-png.flaticon.com/512/2540/2540201.png" alt="sensors"></ion-img>
              </ion-row>
              <ion-row class="ion-justify-content-center">  Tap to see</ion-row>
          
                  
        </ion-card>
        <ion-grid>
            <ion-row>
                <ion-col>
                    <router-link :to="{ path: '/homepage/3', params: {channel: 3 }}">
                        <ion-card  :color="colorWind" >
                            <ion-img class="img" src="data:image/png;base64,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    " />
                            <ion-card-header>
                                <ion-card-subtitle>{{lastWind}}</ion-card-subtitle>
                                <ion-card-title>Wind</ion-card-title>
                            </ion-card-header>
                        </ion-card>
                    </router-link>     
                </ion-col>
                <ion-col>
                    <router-link :to="{ path: '/homepage/4', params: {channel: 4 }}">
                        <ion-card  :color="colorSmoke">
                            <ion-img class="img" src="https://thumbs.dreamstime.com/b/black-smoke-color-icon-vector-black-smoke-sign-isolated-symbol-illustration-black-smoke-color-icon-vector-illustration-219873818.jpg" />
                            <ion-card-header>
                                <ion-card-subtitle>{{lastSmoke}}</ion-card-subtitle>
                                <ion-card-title>Smoke</ion-card-title>
                            </ion-card-header>
                        </ion-card>
                    </router-link>
                </ion-col>
            </ion-row>
            <ion-row>
                <ion-col>
                    <router-link :to="{ path: '/homepage/1', params: {channel: 1 }}">
                        <ion-card  :color="colorTemp">
                            <ion-img class="img" src="data:image/png;base64,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" />
                            <ion-card-header>
                                <ion-card-subtitle>{{lastTemp}}</ion-card-subtitle>
                                <ion-card-title>Temperature</ion-card-title>
                            </ion-card-header>
                        </ion-card>
                    </router-link>
                </ion-col>
                <ion-col>
                    <router-link :to="{ path: '/homepage/2', params: {channel: 2 }}">
                        <ion-card :color="colorHum">
                            <ion-img class="img" src="data:image/png;base64,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" />
                            <ion-card-header>
                                <ion-card-subtitle>{{lastHum}}</ion-card-subtitle>
                                <ion-card-title>Humidity</ion-card-title>
                            </ion-card-header>
                        </ion-card>
                    </router-link>
                </ion-col>
            </ion-row>
        </ion-grid>
  </base-layout>
</template>

<script>
import {IonGrid, IonRow, IonCol, IonImg, IonCard, IonIcon, modalController} from '@ionic/vue'
import axios from 'axios'
import { LocalNotifications } from '@capacitor/local-notifications';
// import { ScreenReader } from '@capacitor/screen-reader';
import { TextToSpeech } from '@capacitor-community/text-to-speech';
import { helpCircle, mapOutline, locateOutline } from 'ionicons/icons';
import ModalComp from '../components/ModalHome.vue';




export default{
    setup() {
    const openModal = async () => {
      const modal = await modalController.create({
        component: ModalComp, //Modal is name of the component to render inside ionic modal
      });
      return modal.present();
    };

    return { openModal };
  },
    data() {
        return {
            lastTemp : 0,
            lastWind : 0,
            lastHum : 0,
            lastSmoke : 0,
            colorTemp: "primary",
            colorHum: "primary",
            colorWind: "primary",
            colorSmoke: "primary",
            colorHome: "primary",
            messageHome: "",
            submessageHome: "",
            weatherPrediction: 0.00,
            notificationMessage:"",
            helpCircle,
            mapOutline,
            locateOutline

        }
    },
    components: {
        IonGrid,
        IonRow,
        IonCol,
        IonImg,
        IonCard,
        IonIcon
        
    },
    methods: {
    // screeenReader() {
    //     console.log('hhhmmmm');
    //     ScreenReader.addListener('screenReaderStateChange', ({value}) => {
    //         console.log(`Screen reader is now ${value ? 'on' : 'off'}`);
    //     });
    // },
    // async checkScreenReaderEnabled(){
    //     const { value } = await ScreenReader.isEnabled();

    //     alert('Voice over enabled? ' + value);
    //     console.log('Voice over enabled? ' + value);
    //     this.sayHello();
    // },
    // async sayHello(){
    //     await ScreenReader.speak({ value: 'Careful, possible wildfire at SouthEast Sensor, with Strong Winds ' });
    // },
    async speak(val) {
        await TextToSpeech.speak({
            text: val,
            lang: 'en',
            rate: 1.0,
            pitch: 1.0,
            volume: 1.0,
            category: 'ambient',
        });
    },
    async scheduleNotification(){
        LocalNotifications.schedule({
            notifications: [
                {
                title: "Danger!",
                body: this.notificationMessage,
                id: 1,
                schedule: { at: new Date(Date.now() + 1000 * 5) },
                sound: null,
                attachments: null,
                actionTypeId: "",
                extra: null,
                }
            ]
        });
        console.log("hmmm")
    },
        lastFeed() {
            axios
            .get("https://api.thingspeak.com/channels/1642633/feeds.json?results=2")
            .then((response) => {
                console.log(response.data.feeds[1].field1,"done");
                this.lastTemp = response.data.feeds[1].field1;
                this.lastHum = response.data.feeds[1].field2;
                this.lastWind = response.data.feeds[1].field3;
                this.lastSmoke = response.data.feeds[1].field4;
                this.colors()
                    
            })
            .catch(error => {
                console.log(error.response,"wrong"); 
            })
        },
        getweather() {
            axios
            .get("https://api.openweathermap.org/data/2.5/weather?lat=40.62&lon=22.94&appid=YOURAPIKEY")
            .then((response) => {
                console.log(response,"right");
                const pred = response.data.main.temp - 273.15;
                this.weatherPrediction = pred;
                console.log(this.weatherPrediction);
                    
            })
            .catch(error => {
                console.log(error.response,"wrong"); 
            })
        },
        colors() {
            //Temperature
            this.notificationMessage = ""
            if (this.lastTemp > (this.weatherPrediction + 10.00) && this.lastTemp <= (this.weatherPrediction + 15.00)) {
                this.colorTemp = "warning"
            }
            else if(this.lastTemp > (this.weatherPrediction + 15.00)) {
                this.colorTemp = "danger"
                this.notificationMessage +=" High Temperature"
            }
            else {
                this.colorTemp = "primary"
                console.log("fawefawef",this.weatherPrediction);
            }
            //Wind
            if (this.lastWind > 15 && this.lastWind <= 90.00) {
                this.colorWind = "warning"
                this.notificationMessage +=" and Moderate Wind"
            }
            else if(this.lastWind > 90.00) {
                this.colorWind = "danger"
                this.notificationMessage +=" and Strong Wind"
            }
            else {
                this.colorWind = "primary"
            }
            // Humidity
            if (this.lastHum < 10.00) {
                this.colorHum = "warning"
            }
            else {
                this.colorHum = "primary"
            }
            //Smoke
            if (this.lastSmoke > 300.00 && this.lastSmoke<= 600.00) {
                this.colorSmoke = "warning"
            }
            else if(this.lastWind > 600.00) {
                this.colorSmoke = "danger"
                this.notificationMessage +=" and Smoke Detected!"
            }
            else {
                this.colorSmoke = "primary"
            }
            if (this.colorSmoke == "danger" || this.colorTemp == "danger" ||this.colorWind == "danger") {
                this.colorHome = "danger"
                this.messageHome = "Danger"
                this.submessageHome = "Check the Red values and your Sensors !!"
                this.scheduleNotification();
                this.$store.getters.memories[0].status = "red"
                // this.speak("Danger! There is a possible fire from SouthEast");
            } else if (this.colorSmoke == "warning" || this.colorTemp == "warning" ||this.colorWind == "warning" || this.colorHum == "warning") {
                this.colorHome = "warning"
                this.messageHome = "Warning"
                this.submessageHome = "One or more of your sensors is Yellow, check them!"
                this.$store.getters.memories[0].status = "yellow"
                this.speak(this.submessageHome);                
            } else {
                this.colorHome = "primary"
                this.messageHome = "Safe"
                this.submessageHome = "Everything is normal"
                this.$store.getters.memories[0].status = "blue"
            }
            
        }
    },
    mounted() {
        this.lastFeed(),
        this.getweather()
    },
    created(){
        this.interval = setInterval(() =>{
        this.lastFeed()},16000)
        // this.screeenReader()
        
    },
    unmounted(){
        clearInterval(this.interval)
    }

}
</script>

<style scoped>
    h1 {
        text-align: center;
        font-weight: bold;
    }       
    h2 {
        text-align: center;
        font-weight: bold;
    }  
    .ok {
        height: 250px;
    }

    .img {
        width: 100px;
        height: 100px;
    }
    
</style>