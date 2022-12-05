
#include <pgmspace.h>

char css[] PROGMEM = R"=====(
.logo{ padding-left:55px;background-size: 37px 16px;height: 17px; background-repeat: no-repeat;background-image: url("data:image/svg+xml,%3Csvg width='469' height='197' viewBox='0 0 469 197' fill='none' xmlns='http://www.w3.org/2000/svg'%3E%3Crect width='469' height='197' fill='%23F2F2F2'/%3E%3Crect width='469' height='197' fill='white'/%3E%3Cpath d='M127.125 196C158.396 196 184.026 186.794 204.016 168.382C224.005 149.97 234 126.212 234 97.1091C234 68.0061 224.104 44.5455 204.312 26.7273C184.521 8.90909 158.792 0 127.125 0H63V196H127.125Z' fill='%233D568A'/%3E%3Cpath d='M0 156V40H127.837C148.103 40 164.197 45.1122 176.118 55.3365C188.039 65.5609 194 79.5962 194 97.4423C194 115.103 187.94 129.324 175.82 140.106C163.501 150.702 147.507 156 127.837 156H0Z' fill='%2332C5FF'/%3E%3Cpath d='M54.8659 136V96.0774L73.1454 119.714H77.9906L96.2701 96.0774V136H111.136V60H106.291L75.568 100.488L44.8452 60H40V136H54.8659Z' fill='white'/%3E%3Cpath d='M135.241 136V108.011C135.241 103.251 136.554 99.6253 139.181 97.1324C141.808 94.6394 145.416 93.393 150.004 93.393H154V79.9084C152.594 79.4551 150.966 79.2285 149.116 79.2285C142.826 79.2285 137.794 81.7215 134.02 86.7073V79.9084H120.256V136H135.241Z' fill='white'/%3E%3Cpath d='M284 98V1H244V98H284Z' fill='%233D568A'/%3E%3Cpath d='M284 197V98H244V197H284Z' fill='%2332C5FF'/%3E%3Cpath d='M401.669 119.703L469 1H424.805L381.5 78.7506L338.492 1H294L361.627 120L401.669 119.703Z' fill='%2332C5FF'/%3E%3Cpath d='M402 197V119.261L381.852 78L362 119.56V197H402Z' fill='%233D568A'/%3E%3C/svg%3E"); }
.card-body{padding: 1rem 0rem!important;}
.form-check-input:checked {background-color: #33c5ff;border-color: #33c5ff;}
.btn-primary, .sensor_header { background-color: #33C5FF!important; border-color:#33C5FF!important; color: #fff!important;}
.text-left{text-align:left}
.text-right{text-align:right}
.pointer{cursor:pointer;}
.alert-secondary {color: #383d41;background-color: #e2e3e5;border-color: #d6d8db;}
)=====";

char bootstrap[] PROGMEM = R"=====(

:root{--bs-blue:#0d6efd;--bs-indigo:#6610f2;--bs-purple:#6f42c1;--bs-pink:#d63384;--bs-red:#dc3545;--bs-orange:#fd7e14;--bs-yellow:#ffc107;--bs-green:#198754;--bs-teal:#20c997;--bs-cyan:#0dcaf0;--bs-white:#fff;--bs-gray:#6c757d;--bs-gray-dark:#343a40;--bs-primary:#0d6efd;--bs-secondary:#6c757d;--bs-success:#198754;--bs-info:#0dcaf0;--bs-warning:#ffc107;--bs-danger:#dc3545;--bs-light:#f8f9fa;--bs-dark:#212529;--bs-font-sans-serif:system-ui,-apple-system,"Segoe UI",Roboto,"Helvetica Neue",Arial,"Noto Sans","Liberation Sans",sans-serif,"Apple Color Emoji","Segoe UI Emoji","Segoe UI Symbol","Noto Color Emoji";--bs-font-monospace:SFMono-Regular,Menlo,Monaco,Consolas,"Liberation Mono","Courier New",monospace;--bs-gradient:linear-gradient(180deg, rgba(255, 255, 255, 0.15), rgba(255, 255, 255, 0))}*,::after,::before{box-sizing:border-box}@media (prefers-reduced-motion:no-preference){:root{scroll-behavior:smooth}}body{margin:0;font-family:var(--bs-font-sans-serif);font-size:1rem;font-weight:400;line-height:1.5;color:#212529;background-color:#fff;-webkit-text-size-adjust:100%;-webkit-tap-highlight-color:transparent}p{margin-top:0;margin-bottom:1rem}strong{font-weight:bolder}a{color:#0d6efd;text-decoration:underline}a:hover{color:#0a58ca}svg{vertical-align:middle}label{display:inline-block}button{border-radius:0}button:focus:not(:focus-visible){outline:0}button,input{margin:0;font-family:inherit;font-size:inherit;line-height:inherit}button{text-transform:none}[type=submit],button{-webkit-appearance:button}[type=button]:not(:disabled),[type=reset]:not(:disabled),[type=submit]:not(:disabled),button:not(:disabled){cursor:pointer}::-moz-focus-inner{padding:0;border-style:none}::-webkit-datetime-edit-day-field,::-webkit-datetime-edit-fields-wrapper,::-webkit-datetime-edit-hour-field,::-webkit-datetime-edit-minute,::-webkit-datetime-edit-month-field,::-webkit-datetime-edit-text,::-webkit-datetime-edit-year-field{padding:0}::-webkit-inner-spin-button{height:auto}::-webkit-search-decoration{-webkit-appearance:none}::-webkit-color-swatch-wrapper{padding:0}::file-selector-button{font:inherit}::-webkit-file-upload-button{font:inherit;-webkit-appearance:button}.container{width:100%;padding-right:var(--bs-gutter-x,.75rem);padding-left:var(--bs-gutter-x,.75rem);margin-right:auto;margin-left:auto}@media (min-width:576px){.container{max-width:540px}}@media (min-width:768px){.container{max-width:720px}}@media (min-width:992px){.container{max-width:960px}}@media (min-width:1200px){.container{max-width:1140px}}@media (min-width:1400px){.container{max-width:1320px}}.row{--bs-gutter-x:1.5rem;--bs-gutter-y:0;display:flex;flex-wrap:wrap;margin-top:calc(var(--bs-gutter-y) * -1);margin-right:calc(var(--bs-gutter-x) * -.5);margin-left:calc(var(--bs-gutter-x) * -.5)}.row>*{flex-shrink:0;width:100%;max-width:100%;padding-right:calc(var(--bs-gutter-x) * .5);padding-left:calc(var(--bs-gutter-x) * .5);margin-top:var(--bs-gutter-y)}.col-12{flex:0 0 auto;width:100%}@media (min-width:768px){.col-md-5{flex:0 0 auto;width:41.66666667%}.col-md-6{flex:0 0 auto;width:50%}}@media (min-width:992px){.col-lg-4{flex:0 0 auto;width:33.33333333%}.col-lg-7{flex:0 0 auto;width:58.33333333%}}.form-label{margin-bottom:.5rem}.form-control{display:block;width:100%;padding:.375rem .75rem;font-size:1rem;font-weight:400;line-height:1.5;color:#212529;background-color:#fff;background-clip:padding-box;border:1px solid #ced4da;-webkit-appearance:none;-moz-appearance:none;appearance:none;border-radius:.25rem;transition:border-color .15s ease-in-out,box-shadow .15s ease-in-out}@media (prefers-reduced-motion:reduce){.form-control{transition:none}}.form-control[type=file]:not(:disabled):not([readonly]){cursor:pointer}.form-control:focus{color:#212529;background-color:#fff;border-color:#86b7fe;outline:0;box-shadow:0 0 0 .25rem rgba(13,110,253,.25)}.form-control::-webkit-date-and-time-value{height:1.5em}.form-control::-moz-placeholder{color:#6c757d;opacity:1}.form-control:disabled{background-color:#e9ecef;opacity:1}.form-control::file-selector-button{padding:.375rem .75rem;margin:-.375rem -.75rem;-webkit-margin-end:.75rem;margin-inline-end:.75rem;color:#212529;background-color:#e9ecef;pointer-events:none;border-color:inherit;border-style:solid;border-width:0;border-inline-end-width:1px;border-radius:0;transition:color .15s ease-in-out,background-color .15s ease-in-out,border-color .15s ease-in-out,box-shadow .15s ease-in-out}@media (prefers-reduced-motion:reduce){.form-control::file-selector-button{transition:none}}.form-control:hover:not(:disabled):not([readonly])::file-selector-button{background-color:#dde0e3}.form-control::-webkit-file-upload-button{padding:.375rem .75rem;margin:-.375rem -.75rem;-webkit-margin-end:.75rem;margin-inline-end:.75rem;color:#212529;background-color:#e9ecef;pointer-events:none;border-color:inherit;border-style:solid;border-width:0;border-inline-end-width:1px;border-radius:0;-webkit-transition:color .15s ease-in-out,background-color .15s ease-in-out,border-color .15s ease-in-out,box-shadow .15s ease-in-out;transition:color .15s ease-in-out,background-color .15s ease-in-out,border-color .15s ease-in-out,box-shadow .15s ease-in-out}@media (prefers-reduced-motion:reduce){.form-control::-webkit-file-upload-button{-webkit-transition:none;transition:none}}.form-control:hover:not(:disabled):not([readonly])::-webkit-file-upload-button{background-color:#dde0e3}.form-control-sm::file-selector-button{padding:.25rem .5rem;margin:-.25rem -.5rem;-webkit-margin-end:.5rem;margin-inline-end:.5rem}.form-control-lg::file-selector-button{padding:.5rem 1rem;margin:-.5rem -1rem;-webkit-margin-end:1rem;margin-inline-end:1rem}.form-control-color:not(:disabled):not([readonly]){cursor:pointer}.form-check{display:block;min-height:1.5rem;padding-left:1.5em;margin-bottom:.125rem}.form-check .form-check-input{float:left;margin-left:-1.5em}.form-check-input{width:1em;height:1em;margin-top:.25em;vertical-align:top;background-color:#fff;background-repeat:no-repeat;background-position:center;background-size:contain;border:1px solid rgba(0,0,0,.25);-webkit-appearance:none;-moz-appearance:none;appearance:none;-webkit-print-color-adjust:exact;color-adjust:exact}.form-check-input[type=radio]{border-radius:50%}.form-check-input:active{filter:brightness(90%)}.form-check-input:focus{border-color:#86b7fe;outline:0;box-shadow:0 0 0 .25rem rgba(13,110,253,.25)}.form-check-input:checked{background-color:#0d6efd;border-color:#0d6efd}.form-check-input:checked[type=radio]{background-image:url("data:image/svg+xml,%3csvg xmlns='http://www.w3.org/2000/svg' viewBox='-4 -4 8 8'%3e%3ccircle r='2' fill='%23fff'/%3e%3c/svg%3e")}.form-check-input:disabled{pointer-events:none;filter:none;opacity:.5}.form-check-input:disabled~.form-check-label{opacity:.5}.form-check-inline{display:inline-block;margin-right:1rem}.form-floating{position:relative}.form-floating>.form-control:not(:-moz-placeholder-shown){padding-top:1.625rem;padding-bottom:.625rem}.form-floating>.form-control:not(:-moz-placeholder-shown)~label{opacity:.65;transform:scale(.85) translateY(-.5rem) translateX(.15rem)}.btn{display:inline-block;font-weight:400;line-height:1.5;color:#212529;text-align:center;text-decoration:none;vertical-align:middle;cursor:pointer;-webkit-user-select:none;-moz-user-select:none;user-select:none;background-color:transparent;border:1px solid transparent;padding:.375rem .75rem;font-size:1rem;border-radius:.25rem;transition:color .15s ease-in-out,background-color .15s ease-in-out,border-color .15s ease-in-out,box-shadow .15s ease-in-out}@media (prefers-reduced-motion:reduce){.btn{transition:none}}.btn:hover{color:#212529}.btn:focus{outline:0;box-shadow:0 0 0 .25rem rgba(13,110,253,.25)}.btn:disabled{pointer-events:none;opacity:.65}.btn-primary{color:#fff;background-color:#0d6efd;border-color:#0d6efd}.btn-primary:hover{color:#fff;background-color:#0b5ed7;border-color:#0a58ca}.btn-primary:focus{color:#fff;background-color:#0b5ed7;border-color:#0a58ca;box-shadow:0 0 0 .25rem rgba(49,132,253,.5)}.btn-primary:active{color:#fff;background-color:#0a58ca;border-color:#0a53be}.btn-primary:active:focus{box-shadow:0 0 0 .25rem rgba(49,132,253,.5)}.btn-primary:disabled{color:#fff;background-color:#0d6efd;border-color:#0d6efd}.btn-lg{padding:.5rem 1rem;font-size:1.25rem;border-radius:.3rem}.d-flex{display:flex!important}.d-inline-flex{display:inline-flex!important}.border{border:1px solid #dee2e6!important}.border-bottom{border-bottom:1px solid #dee2e6!important}.border-1{border-width:1px!important}.flex-column{flex-direction:column!important}.justify-content-between{justify-content:space-between!important}.align-items-center{align-items:center!important}.mt-2{margin-top:.5rem!important}.mt-3{margin-top:1rem!important}.mt-4{margin-top:1.5rem!important}.mt-5{margin-top:3rem!important}.me-3{margin-right:1rem!important}.me-5{margin-right:3rem!important}.mb-4{margin-bottom:1.5rem!important}.p-4{padding:1.5rem!important}.py-2{padding-top:.5rem!important;padding-bottom:.5rem!important}.py-3{padding-top:1rem!important;padding-bottom:1rem!important}.pb-3{padding-bottom:1rem!important}.fs-4{font-size:calc(1.275rem + .3vw)!important}.text-decoration-none{text-decoration:none!important}.text-break{word-wrap:break-word!important;word-break:break-word!important}.text-dark{color:#212529!important}.bg-light{background-color:#f8f9fa!important}.rounded-3{border-radius:.3rem!important}@media (min-width:768px){.flex-md-row{flex-direction:row!important}.order-md-last{order:6!important}.mt-md-0{margin-top:0!important}.ms-md-auto{margin-left:auto!important}}@media (min-width:1200px){.fs-4{font-size:1.5rem!important}}:root{--bs-blue:#0d6efd;--bs-indigo:#6610f2;--bs-purple:#6f42c1;--bs-pink:#d63384;--bs-red:#dc3545;--bs-orange:#fd7e14;--bs-yellow:#ffc107;--bs-green:#198754;--bs-teal:#20c997;--bs-cyan:#0dcaf0;--bs-white:#fff;--bs-gray:#6c757d;--bs-gray-dark:#343a40;--bs-primary:#0d6efd;--bs-secondary:#6c757d;--bs-success:#198754;--bs-info:#0dcaf0;--bs-warning:#ffc107;--bs-danger:#dc3545;--bs-light:#f8f9fa;--bs-dark:#212529;--bs-font-sans-serif:system-ui,-apple-system,"Segoe UI",Roboto,"Helvetica Neue",Arial,"Noto Sans","Liberation Sans",sans-serif,"Apple Color Emoji","Segoe UI Emoji","Segoe UI Symbol","Noto Color Emoji";--bs-font-monospace:SFMono-Regular,Menlo,Monaco,Consolas,"Liberation Mono","Courier New",monospace;--bs-gradient:linear-gradient(180deg, rgba(255, 255, 255, 0.15), rgba(255, 255, 255, 0))}*,::after,::before{box-sizing:border-box}@media (prefers-reduced-motion:no-preference){:root{scroll-behavior:smooth}}body{margin:0;font-family:var(--bs-font-sans-serif);font-size:1rem;font-weight:400;line-height:1.5;color:#212529;background-color:#fff;-webkit-text-size-adjust:100%;-webkit-tap-highlight-color:transparent}h2{margin-top:0;margin-bottom:.5rem;font-weight:500;line-height:1.2}h2{font-size:calc(1.325rem + .9vw)}@media (min-width:1200px){h2{font-size:2rem}}p{margin-top:0;margin-bottom:1rem}ul{padding-left:2rem}ul{margin-top:0;margin-bottom:1rem}small{font-size:.875em}a{color:#0d6efd;text-decoration:underline}a:hover{color:#0a58ca}svg{vertical-align:middle}button:focus:not(:focus-visible){outline:0}[type=button]:not(:disabled),[type=reset]:not(:disabled),[type=submit]:not(:disabled),button:not(:disabled){cursor:pointer}::-moz-focus-inner{padding:0;border-style:none}::-webkit-datetime-edit-day-field,::-webkit-datetime-edit-fields-wrapper,::-webkit-datetime-edit-hour-field,::-webkit-datetime-edit-minute,::-webkit-datetime-edit-month-field,::-webkit-datetime-edit-text,::-webkit-datetime-edit-year-field{padding:0}::-webkit-inner-spin-button{height:auto}::-webkit-search-decoration{-webkit-appearance:none}::-webkit-color-swatch-wrapper{padding:0}::file-selector-button{font:inherit}::-webkit-file-upload-button{font:inherit;-webkit-appearance:button}.list-unstyled{padding-left:0;list-style:none}.container{width:100%;padding-right:var(--bs-gutter-x,.75rem);padding-left:var(--bs-gutter-x,.75rem);margin-right:auto;margin-left:auto}@media (min-width:576px){.container{max-width:540px}}@media (min-width:768px){.container{max-width:720px}}@media (min-width:992px){.container{max-width:960px}}@media (min-width:1200px){.container{max-width:1140px}}@media (min-width:1400px){.container{max-width:1320px}}.row{--bs-gutter-x:1.5rem;--bs-gutter-y:0;display:flex;flex-wrap:wrap;margin-top:calc(var(--bs-gutter-y) * -1);margin-right:calc(var(--bs-gutter-x) * -.5);margin-left:calc(var(--bs-gutter-x) * -.5)}.row>*{flex-shrink:0;width:100%;max-width:100%;padding-right:calc(var(--bs-gutter-x) * .5);padding-left:calc(var(--bs-gutter-x) * .5);margin-top:var(--bs-gutter-y)}.col{flex:1 0 0%}.row-cols-1>*{flex:0 0 auto;width:100%}@media (min-width:768px){.row-cols-md-3>*{flex:0 0 auto;width:33.3333333333%}}@media (min-width:992px){.row-cols-lg-4>*{flex:0 0 auto;width:25%}}@media (min-width:1200px){.row-cols-xl-5>*{flex:0 0 auto;width:20%}}.form-control[type=file]:not(:disabled):not([readonly]){cursor:pointer}.form-control::file-selector-button{padding:.375rem .75rem;margin:-.375rem -.75rem;-webkit-margin-end:.75rem;margin-inline-end:.75rem;color:#212529;background-color:#e9ecef;pointer-events:none;border-color:inherit;border-style:solid;border-width:0;border-inline-end-width:1px;border-radius:0;transition:color .15s ease-in-out,background-color .15s ease-in-out,border-color .15s ease-in-out,box-shadow .15s ease-in-out}@media (prefers-reduced-motion:reduce){.form-control::file-selector-button{transition:none}}.form-control:hover:not(:disabled):not([readonly])::file-selector-button{background-color:#dde0e3}.form-control:hover:not(:disabled):not([readonly])::-webkit-file-upload-button{background-color:#dde0e3}.form-control-sm::file-selector-button{padding:.25rem .5rem;margin:-.25rem -.5rem;-webkit-margin-end:.5rem;margin-inline-end:.5rem}.form-control-lg::file-selector-button{padding:.5rem 1rem;margin:-.5rem -1rem;-webkit-margin-end:1rem;margin-inline-end:1rem}.form-control-color:not(:disabled):not([readonly]){cursor:pointer}.form-floating>.form-control:not(:-moz-placeholder-shown){padding-top:1.625rem;padding-bottom:.625rem}.form-floating>.form-control:not(:-moz-placeholder-shown)~label{opacity:.65;transform:scale(.85) translateY(-.5rem) translateX(.15rem)}.card{position:relative;display:flex;flex-direction:column;min-width:0;word-wrap:break-word;background-color:#fff;background-clip:border-box;border:1px solid rgba(0,0,0,.125);border-radius:.25rem}.card-body{flex:1 1 auto;padding:1rem 1rem}.card-title{margin-bottom:.5rem}.card-header{padding:.5rem 1rem;margin-bottom:0;background-color:rgba(0,0,0,.03);border-bottom:1px solid rgba(0,0,0,.125)}.card-header:first-child{border-radius:calc(.25rem - 1px) calc(.25rem - 1px) 0 0}.alert{position:relative;padding:1rem 1rem;margin-bottom:1rem;border:1px solid transparent;border-radius:.25rem}.alert-danger{color:#842029;background-color:#f8d7da;border-color:#f5c2c7}.d-flex{display:flex!important}.d-inline-flex{display:inline-flex!important}.d-none{display:none!important}.shadow-sm{box-shadow:0 .125rem .25rem rgba(0,0,0,.075)!important}.border-bottom{border-bottom:1px solid #dee2e6!important}.flex-column{flex-direction:column!important}.align-items-center{align-items:center!important}.my-0{margin-top:0!important;margin-bottom:0!important}.mt-2{margin-top:.5rem!important}.mt-3{margin-top:1rem!important}.me-3{margin-right:1rem!important}.me-4{margin-right:1.5rem!important}.mb-3{margin-bottom:1rem!important}.mb-4{margin-bottom:1.5rem!important}.py-2{padding-top:.5rem!important;padding-bottom:.5rem!important}.py-3{padding-top:1rem!important;padding-bottom:1rem!important}.pb-3{padding-bottom:1rem!important}.fs-4{font-size:calc(1.275rem + .3vw)!important}.fw-normal{font-weight:400!important}.text-center{text-align:center!important}.text-decoration-none{text-decoration:none!important}.text-danger{color:#dc3545!important}.text-dark{color:#212529!important}.rounded-3{border-radius:.3rem!important}@media (min-width:576px){.p-sm-3{padding:1rem!important}}@media (min-width:768px){.flex-md-row{flex-direction:row!important}.mt-md-0{margin-top:0!important}.ms-md-auto{margin-left:auto!important}}@media (min-width:1200px){.fs-4{font-size:1.5rem!important}}:root{--bs-blue:#0d6efd;--bs-indigo:#6610f2;--bs-purple:#6f42c1;--bs-pink:#d63384;--bs-red:#dc3545;--bs-orange:#fd7e14;--bs-yellow:#ffc107;--bs-green:#198754;--bs-teal:#20c997;--bs-cyan:#0dcaf0;--bs-white:#fff;--bs-gray:#6c757d;--bs-gray-dark:#343a40;--bs-gray-100:#f8f9fa;--bs-gray-200:#e9ecef;--bs-gray-300:#dee2e6;--bs-gray-400:#ced4da;--bs-gray-500:#adb5bd;--bs-gray-600:#6c757d;--bs-gray-700:#495057;--bs-gray-800:#343a40;--bs-gray-900:#212529;--bs-primary:#0d6efd;--bs-secondary:#6c757d;--bs-success:#198754;--bs-info:#0dcaf0;--bs-warning:#ffc107;--bs-danger:#dc3545;--bs-light:#f8f9fa;--bs-dark:#212529;--bs-primary-rgb:13,110,253;--bs-secondary-rgb:108,117,125;--bs-success-rgb:25,135,84;--bs-info-rgb:13,202,240;--bs-warning-rgb:255,193,7;--bs-danger-rgb:220,53,69;--bs-light-rgb:248,249,250;--bs-dark-rgb:33,37,41;--bs-white-rgb:255,255,255;--bs-black-rgb:0,0,0;--bs-body-color-rgb:33,37,41;--bs-body-bg-rgb:255,255,255;--bs-font-sans-serif:system-ui,-apple-system,"Segoe UI",Roboto,"Helvetica Neue",Arial,"Noto Sans","Liberation Sans",sans-serif,"Apple Color Emoji","Segoe UI Emoji","Segoe UI Symbol","Noto Color Emoji";--bs-font-monospace:SFMono-Regular,Menlo,Monaco,Consolas,"Liberation Mono","Courier New",monospace;--bs-gradient:linear-gradient(180deg, rgba(255, 255, 255, 0.15), rgba(255, 255, 255, 0));--bs-body-font-family:var(--bs-font-sans-serif);--bs-body-font-size:1rem;--bs-body-font-weight:400;--bs-body-line-height:1.5;--bs-body-color:#212529;--bs-body-bg:#fff}.container,.container-lg,.container-md,.container-sm,.container-xl{width:100%;padding-right:var(--bs-gutter-x,.75rem);padding-left:var(--bs-gutter-x,.75rem);margin-right:auto;margin-left:auto}@media (min-width:576px){.container,.container-sm{max-width:540px}}@media (min-width:768px){.container,.container-md,.container-sm{max-width:720px}}@media (min-width:992px){.container,.container-lg,.container-md,.container-sm{max-width:960px}}@media (min-width:1200px){.container,.container-lg,.container-md,.container-sm,.container-xl{max-width:1140px}}@media (min-width:1400px){.container,.container-lg,.container-md,.container-sm,.container-xl{max-width:1320px}}.row{--bs-gutter-x:1.5rem;--bs-gutter-y:0;display:flex;flex-wrap:wrap;margin-top:calc(var(--bs-gutter-y) * -1);margin-right:calc(var(--bs-gutter-x) * -.5);margin-left:calc(var(--bs-gutter-x) * -.5)}.row>*{box-sizing:border-box;flex-shrink:0;width:100%;max-width:100%;padding-right:calc(var(--bs-gutter-x) * .5);padding-left:calc(var(--bs-gutter-x) * .5);margin-top:var(--bs-gutter-y)}.col{flex:1 0 0%}.row-cols-auto>*{flex:0 0 auto;width:auto}.row-cols-1>*{flex:0 0 auto;width:100%}.row-cols-2>*{flex:0 0 auto;width:50%}.row-cols-3>*{flex:0 0 auto;width:33.3333333333%}.row-cols-4>*{flex:0 0 auto;width:25%}.row-cols-5>*{flex:0 0 auto;width:20%}.row-cols-6>*{flex:0 0 auto;width:16.6666666667%}.col-auto{flex:0 0 auto;width:auto}.col-1{flex:0 0 auto;width:8.33333333%}.col-2{flex:0 0 auto;width:16.66666667%}.col-3{flex:0 0 auto;width:25%}.col-4{flex:0 0 auto;width:33.33333333%}.col-5{flex:0 0 auto;width:41.66666667%}.col-6{flex:0 0 auto;width:50%}.col-7{flex:0 0 auto;width:58.33333333%}.col-8{flex:0 0 auto;width:66.66666667%}.col-9{flex:0 0 auto;width:75%}.col-10{flex:0 0 auto;width:83.33333333%}.col-11{flex:0 0 auto;width:91.66666667%}.col-12{flex:0 0 auto;width:100%}@media (min-width:576px){.col-sm{flex:1 0 0%}.row-cols-sm-auto>*{flex:0 0 auto;width:auto}.row-cols-sm-1>*{flex:0 0 auto;width:100%}.row-cols-sm-2>*{flex:0 0 auto;width:50%}.row-cols-sm-3>*{flex:0 0 auto;width:33.3333333333%}.row-cols-sm-4>*{flex:0 0 auto;width:25%}.row-cols-sm-5>*{flex:0 0 auto;width:20%}.row-cols-sm-6>*{flex:0 0 auto;width:16.6666666667%}.col-sm-auto{flex:0 0 auto;width:auto}.col-sm-1{flex:0 0 auto;width:8.33333333%}.col-sm-2{flex:0 0 auto;width:16.66666667%}.col-sm-3{flex:0 0 auto;width:25%}.col-sm-4{flex:0 0 auto;width:33.33333333%}.col-sm-5{flex:0 0 auto;width:41.66666667%}.col-sm-6{flex:0 0 auto;width:50%}.col-sm-7{flex:0 0 auto;width:58.33333333%}.col-sm-8{flex:0 0 auto;width:66.66666667%}.col-sm-9{flex:0 0 auto;width:75%}.col-sm-10{flex:0 0 auto;width:83.33333333%}.col-sm-11{flex:0 0 auto;width:91.66666667%}.col-sm-12{flex:0 0 auto;width:100%}}@media (min-width:768px){.col-md{flex:1 0 0%}.row-cols-md-auto>*{flex:0 0 auto;width:auto}.row-cols-md-1>*{flex:0 0 auto;width:100%}.row-cols-md-2>*{flex:0 0 auto;width:50%}.row-cols-md-3>*{flex:0 0 auto;width:33.3333333333%}.row-cols-md-4>*{flex:0 0 auto;width:25%}.row-cols-md-5>*{flex:0 0 auto;width:20%}.row-cols-md-6>*{flex:0 0 auto;width:16.6666666667%}.col-md-auto{flex:0 0 auto;width:auto}.col-md-1{flex:0 0 auto;width:8.33333333%}.col-md-2{flex:0 0 auto;width:16.66666667%}.col-md-3{flex:0 0 auto;width:25%}.col-md-4{flex:0 0 auto;width:33.33333333%}.col-md-5{flex:0 0 auto;width:41.66666667%}.col-md-6{flex:0 0 auto;width:50%}.col-md-7{flex:0 0 auto;width:58.33333333%}.col-md-8{flex:0 0 auto;width:66.66666667%}.col-md-9{flex:0 0 auto;width:75%}.col-md-10{flex:0 0 auto;width:83.33333333%}.col-md-11{flex:0 0 auto;width:91.66666667%}.col-md-12{flex:0 0 auto;width:100%}}@media (min-width:992px){.col-lg{flex:1 0 0%}.row-cols-lg-auto>*{flex:0 0 auto;width:auto}.row-cols-lg-1>*{flex:0 0 auto;width:100%}.row-cols-lg-2>*{flex:0 0 auto;width:50%}.row-cols-lg-3>*{flex:0 0 auto;width:33.3333333333%}.row-cols-lg-4>*{flex:0 0 auto;width:25%}.row-cols-lg-5>*{flex:0 0 auto;width:20%}.row-cols-lg-6>*{flex:0 0 auto;width:16.6666666667%}.col-lg-auto{flex:0 0 auto;width:auto}.col-lg-1{flex:0 0 auto;width:8.33333333%}.col-lg-2{flex:0 0 auto;width:16.66666667%}.col-lg-3{flex:0 0 auto;width:25%}.col-lg-4{flex:0 0 auto;width:33.33333333%}.col-lg-5{flex:0 0 auto;width:41.66666667%}.col-lg-6{flex:0 0 auto;width:50%}.col-lg-7{flex:0 0 auto;width:58.33333333%}.col-lg-8{flex:0 0 auto;width:66.66666667%}.col-lg-9{flex:0 0 auto;width:75%}.col-lg-10{flex:0 0 auto;width:83.33333333%}.col-lg-11{flex:0 0 auto;width:91.66666667%}.col-lg-12{flex:0 0 auto;width:100%}}@media (min-width:1200px){.col-xl{flex:1 0 0%}.row-cols-xl-auto>*{flex:0 0 auto;width:auto}.row-cols-xl-1>*{flex:0 0 auto;width:100%}.row-cols-xl-2>*{flex:0 0 auto;width:50%}.row-cols-xl-3>*{flex:0 0 auto;width:33.3333333333%}.row-cols-xl-4>*{flex:0 0 auto;width:25%}.row-cols-xl-5>*{flex:0 0 auto;width:20%}.row-cols-xl-6>*{flex:0 0 auto;width:16.6666666667%}.col-xl-auto{flex:0 0 auto;width:auto}.col-xl-1{flex:0 0 auto;width:8.33333333%}.col-xl-2{flex:0 0 auto;width:16.66666667%}.col-xl-3{flex:0 0 auto;width:25%}.col-xl-4{flex:0 0 auto;width:33.33333333%}.col-xl-5{flex:0 0 auto;width:41.66666667%}.col-xl-6{flex:0 0 auto;width:50%}.col-xl-7{flex:0 0 auto;width:58.33333333%}.col-xl-8{flex:0 0 auto;width:66.66666667%}.col-xl-9{flex:0 0 auto;width:75%}.col-xl-10{flex:0 0 auto;width:83.33333333%}.col-xl-11{flex:0 0 auto;width:91.66666667%}.col-xl-12{flex:0 0 auto;width:100%}}.d-inline{display:inline!important}.d-flex{display:flex!important}.d-inline-flex{display:inline-flex!important}.d-none{display:none!important}.flex-fill{flex:1 1 auto!important}.flex-row{flex-direction:row!important}.flex-column{flex-direction:column!important}.justify-content-center{justify-content:center!important}.justify-content-between{justify-content:space-between!important}.align-items-center{align-items:center!important}.align-content-center{align-content:center!important}.align-content-between{align-content:space-between!important}.order-0{order:0!important}.order-1{order:1!important}.order-2{order:2!important}.order-3{order:3!important}.order-4{order:4!important}.order-5{order:5!important}.order-last{order:6!important}.m-0{margin:0!important}.m-1{margin:.25rem!important}.m-2{margin:.5rem!important}.m-3{margin:1rem!important}.m-4{margin:1.5rem!important}.m-5{margin:3rem!important}.m-auto{margin:auto!important}.my-0{margin-top:0!important;margin-bottom:0!important}.my-1{margin-top:.25rem!important;margin-bottom:.25rem!important}.my-2{margin-top:.5rem!important;margin-bottom:.5rem!important}.my-3{margin-top:1rem!important;margin-bottom:1rem!important}.my-4{margin-top:1.5rem!important;margin-bottom:1.5rem!important}.my-5{margin-top:3rem!important;margin-bottom:3rem!important}.my-auto{margin-top:auto!important;margin-bottom:auto!important}.mt-0{margin-top:0!important}.mt-1{margin-top:.25rem!important}.mt-2{margin-top:.5rem!important}.mt-3{margin-top:1rem!important}.mt-4{margin-top:1.5rem!important}.mt-5{margin-top:3rem!important}.mt-auto{margin-top:auto!important}.me-0{margin-right:0!important}.me-1{margin-right:.25rem!important}.me-2{margin-right:.5rem!important}.me-3{margin-right:1rem!important}.me-4{margin-right:1.5rem!important}.me-5{margin-right:3rem!important}.me-auto{margin-right:auto!important}.mb-0{margin-bottom:0!important}.mb-1{margin-bottom:.25rem!important}.mb-2{margin-bottom:.5rem!important}.mb-3{margin-bottom:1rem!important}.mb-4{margin-bottom:1.5rem!important}.mb-5{margin-bottom:3rem!important}.mb-auto{margin-bottom:auto!important}.ms-0{margin-left:0!important}.ms-1{margin-left:.25rem!important}.ms-2{margin-left:.5rem!important}.ms-3{margin-left:1rem!important}.ms-4{margin-left:1.5rem!important}.ms-5{margin-left:3rem!important}.ms-auto{margin-left:auto!important}.p-0{padding:0!important}.p-1{padding:.25rem!important}.p-2{padding:.5rem!important}.p-3{padding:1rem!important}.p-4{padding:1.5rem!important}.p-5{padding:3rem!important}.px-0{padding-right:0!important;padding-left:0!important}.px-1{padding-right:.25rem!important;padding-left:.25rem!important}.px-2{padding-right:.5rem!important;padding-left:.5rem!important}.px-3{padding-right:1rem!important;padding-left:1rem!important}.px-4{padding-right:1.5rem!important;padding-left:1.5rem!important}.px-5{padding-right:3rem!important;padding-left:3rem!important}.py-0{padding-top:0!important;padding-bottom:0!important}.py-1{padding-top:.25rem!important;padding-bottom:.25rem!important}.py-2{padding-top:.5rem!important;padding-bottom:.5rem!important}.py-3{padding-top:1rem!important;padding-bottom:1rem!important}.py-4{padding-top:1.5rem!important;padding-bottom:1.5rem!important}.py-5{padding-top:3rem!important;padding-bottom:3rem!important}.pb-0{padding-bottom:0!important}.pb-1{padding-bottom:.25rem!important}.pb-2{padding-bottom:.5rem!important}.pb-3{padding-bottom:1rem!important}.pb-4{padding-bottom:1.5rem!important}.pb-5{padding-bottom:3rem!important}@media (min-width:576px){.d-sm-inline{display:inline!important}.d-sm-flex{display:flex!important}.d-sm-inline-flex{display:inline-flex!important}.d-sm-none{display:none!important}.flex-sm-fill{flex:1 1 auto!important}.flex-sm-row{flex-direction:row!important}.flex-sm-column{flex-direction:column!important}.justify-content-sm-center{justify-content:center!important}.justify-content-sm-between{justify-content:space-between!important}.align-items-sm-center{align-items:center!important}.align-content-sm-center{align-content:center!important}.align-content-sm-between{align-content:space-between!important}.order-sm-0{order:0!important}.order-sm-1{order:1!important}.order-sm-2{order:2!important}.order-sm-3{order:3!important}.order-sm-4{order:4!important}.order-sm-5{order:5!important}.order-sm-last{order:6!important}.m-sm-0{margin:0!important}.m-sm-1{margin:.25rem!important}.m-sm-2{margin:.5rem!important}.m-sm-3{margin:1rem!important}.m-sm-4{margin:1.5rem!important}.m-sm-5{margin:3rem!important}.m-sm-auto{margin:auto!important}.my-sm-0{margin-top:0!important;margin-bottom:0!important}.my-sm-1{margin-top:.25rem!important;margin-bottom:.25rem!important}.my-sm-2{margin-top:.5rem!important;margin-bottom:.5rem!important}.my-sm-3{margin-top:1rem!important;margin-bottom:1rem!important}.my-sm-4{margin-top:1.5rem!important;margin-bottom:1.5rem!important}.my-sm-5{margin-top:3rem!important;margin-bottom:3rem!important}.my-sm-auto{margin-top:auto!important;margin-bottom:auto!important}.mt-sm-0{margin-top:0!important}.mt-sm-1{margin-top:.25rem!important}.mt-sm-2{margin-top:.5rem!important}.mt-sm-3{margin-top:1rem!important}.mt-sm-4{margin-top:1.5rem!important}.mt-sm-5{margin-top:3rem!important}.mt-sm-auto{margin-top:auto!important}.me-sm-0{margin-right:0!important}.me-sm-1{margin-right:.25rem!important}.me-sm-2{margin-right:.5rem!important}.me-sm-3{margin-right:1rem!important}.me-sm-4{margin-right:1.5rem!important}.me-sm-5{margin-right:3rem!important}.me-sm-auto{margin-right:auto!important}.mb-sm-0{margin-bottom:0!important}.mb-sm-1{margin-bottom:.25rem!important}.mb-sm-2{margin-bottom:.5rem!important}.mb-sm-3{margin-bottom:1rem!important}.mb-sm-4{margin-bottom:1.5rem!important}.mb-sm-5{margin-bottom:3rem!important}.mb-sm-auto{margin-bottom:auto!important}.ms-sm-0{margin-left:0!important}.ms-sm-1{margin-left:.25rem!important}.ms-sm-2{margin-left:.5rem!important}.ms-sm-3{margin-left:1rem!important}.ms-sm-4{margin-left:1.5rem!important}.ms-sm-5{margin-left:3rem!important}.ms-sm-auto{margin-left:auto!important}.p-sm-0{padding:0!important}.p-sm-1{padding:.25rem!important}.p-sm-2{padding:.5rem!important}.p-sm-3{padding:1rem!important}.p-sm-4{padding:1.5rem!important}.p-sm-5{padding:3rem!important}.px-sm-0{padding-right:0!important;padding-left:0!important}.px-sm-1{padding-right:.25rem!important;padding-left:.25rem!important}.px-sm-2{padding-right:.5rem!important;padding-left:.5rem!important}.px-sm-3{padding-right:1rem!important;padding-left:1rem!important}.px-sm-4{padding-right:1.5rem!important;padding-left:1.5rem!important}.px-sm-5{padding-right:3rem!important;padding-left:3rem!important}.py-sm-0{padding-top:0!important;padding-bottom:0!important}.py-sm-1{padding-top:.25rem!important;padding-bottom:.25rem!important}.py-sm-2{padding-top:.5rem!important;padding-bottom:.5rem!important}.py-sm-3{padding-top:1rem!important;padding-bottom:1rem!important}.py-sm-4{padding-top:1.5rem!important;padding-bottom:1.5rem!important}.py-sm-5{padding-top:3rem!important;padding-bottom:3rem!important}.pb-sm-0{padding-bottom:0!important}.pb-sm-1{padding-bottom:.25rem!important}.pb-sm-2{padding-bottom:.5rem!important}.pb-sm-3{padding-bottom:1rem!important}.pb-sm-4{padding-bottom:1.5rem!important}.pb-sm-5{padding-bottom:3rem!important}}@media (min-width:768px){.d-md-inline{display:inline!important}.d-md-flex{display:flex!important}.d-md-inline-flex{display:inline-flex!important}.d-md-none{display:none!important}.flex-md-fill{flex:1 1 auto!important}.flex-md-row{flex-direction:row!important}.flex-md-column{flex-direction:column!important}.justify-content-md-center{justify-content:center!important}.justify-content-md-between{justify-content:space-between!important}.align-items-md-center{align-items:center!important}.align-content-md-center{align-content:center!important}.align-content-md-between{align-content:space-between!important}.order-md-0{order:0!important}.order-md-1{order:1!important}.order-md-2{order:2!important}.order-md-3{order:3!important}.order-md-4{order:4!important}.order-md-5{order:5!important}.order-md-last{order:6!important}.m-md-0{margin:0!important}.m-md-1{margin:.25rem!important}.m-md-2{margin:.5rem!important}.m-md-3{margin:1rem!important}.m-md-4{margin:1.5rem!important}.m-md-5{margin:3rem!important}.m-md-auto{margin:auto!important}.my-md-0{margin-top:0!important;margin-bottom:0!important}.my-md-1{margin-top:.25rem!important;margin-bottom:.25rem!important}.my-md-2{margin-top:.5rem!important;margin-bottom:.5rem!important}.my-md-3{margin-top:1rem!important;margin-bottom:1rem!important}.my-md-4{margin-top:1.5rem!important;margin-bottom:1.5rem!important}.my-md-5{margin-top:3rem!important;margin-bottom:3rem!important}.my-md-auto{margin-top:auto!important;margin-bottom:auto!important}.mt-md-0{margin-top:0!important}.mt-md-1{margin-top:.25rem!important}.mt-md-2{margin-top:.5rem!important}.mt-md-3{margin-top:1rem!important}.mt-md-4{margin-top:1.5rem!important}.mt-md-5{margin-top:3rem!important}.mt-md-auto{margin-top:auto!important}.me-md-0{margin-right:0!important}.me-md-1{margin-right:.25rem!important}.me-md-2{margin-right:.5rem!important}.me-md-3{margin-right:1rem!important}.me-md-4{margin-right:1.5rem!important}.me-md-5{margin-right:3rem!important}.me-md-auto{margin-right:auto!important}.mb-md-0{margin-bottom:0!important}.mb-md-1{margin-bottom:.25rem!important}.mb-md-2{margin-bottom:.5rem!important}.mb-md-3{margin-bottom:1rem!important}.mb-md-4{margin-bottom:1.5rem!important}.mb-md-5{margin-bottom:3rem!important}.mb-md-auto{margin-bottom:auto!important}.ms-md-0{margin-left:0!important}.ms-md-1{margin-left:.25rem!important}.ms-md-2{margin-left:.5rem!important}.ms-md-3{margin-left:1rem!important}.ms-md-4{margin-left:1.5rem!important}.ms-md-5{margin-left:3rem!important}.ms-md-auto{margin-left:auto!important}.p-md-0{padding:0!important}.p-md-1{padding:.25rem!important}.p-md-2{padding:.5rem!important}.p-md-3{padding:1rem!important}.p-md-4{padding:1.5rem!important}.p-md-5{padding:3rem!important}.px-md-0{padding-right:0!important;padding-left:0!important}.px-md-1{padding-right:.25rem!important;padding-left:.25rem!important}.px-md-2{padding-right:.5rem!important;padding-left:.5rem!important}.px-md-3{padding-right:1rem!important;padding-left:1rem!important}.px-md-4{padding-right:1.5rem!important;padding-left:1.5rem!important}.px-md-5{padding-right:3rem!important;padding-left:3rem!important}.py-md-0{padding-top:0!important;padding-bottom:0!important}.py-md-1{padding-top:.25rem!important;padding-bottom:.25rem!important}.py-md-2{padding-top:.5rem!important;padding-bottom:.5rem!important}.py-md-3{padding-top:1rem!important;padding-bottom:1rem!important}.py-md-4{padding-top:1.5rem!important;padding-bottom:1.5rem!important}.py-md-5{padding-top:3rem!important;padding-bottom:3rem!important}.pb-md-0{padding-bottom:0!important}.pb-md-1{padding-bottom:.25rem!important}.pb-md-2{padding-bottom:.5rem!important}.pb-md-3{padding-bottom:1rem!important}.pb-md-4{padding-bottom:1.5rem!important}.pb-md-5{padding-bottom:3rem!important}}@media (min-width:992px){.d-lg-inline{display:inline!important}.d-lg-flex{display:flex!important}.d-lg-inline-flex{display:inline-flex!important}.d-lg-none{display:none!important}.flex-lg-fill{flex:1 1 auto!important}.flex-lg-row{flex-direction:row!important}.flex-lg-column{flex-direction:column!important}.justify-content-lg-center{justify-content:center!important}.justify-content-lg-between{justify-content:space-between!important}.align-items-lg-center{align-items:center!important}.align-content-lg-center{align-content:center!important}.align-content-lg-between{align-content:space-between!important}.order-lg-0{order:0!important}.order-lg-1{order:1!important}.order-lg-2{order:2!important}.order-lg-3{order:3!important}.order-lg-4{order:4!important}.order-lg-5{order:5!important}.order-lg-last{order:6!important}.m-lg-0{margin:0!important}.m-lg-1{margin:.25rem!important}.m-lg-2{margin:.5rem!important}.m-lg-3{margin:1rem!important}.m-lg-4{margin:1.5rem!important}.m-lg-5{margin:3rem!important}.m-lg-auto{margin:auto!important}.my-lg-0{margin-top:0!important;margin-bottom:0!important}.my-lg-1{margin-top:.25rem!important;margin-bottom:.25rem!important}.my-lg-2{margin-top:.5rem!important;margin-bottom:.5rem!important}.my-lg-3{margin-top:1rem!important;margin-bottom:1rem!important}.my-lg-4{margin-top:1.5rem!important;margin-bottom:1.5rem!important}.my-lg-5{margin-top:3rem!important;margin-bottom:3rem!important}.my-lg-auto{margin-top:auto!important;margin-bottom:auto!important}.mt-lg-0{margin-top:0!important}.mt-lg-1{margin-top:.25rem!important}.mt-lg-2{margin-top:.5rem!important}.mt-lg-3{margin-top:1rem!important}.mt-lg-4{margin-top:1.5rem!important}.mt-lg-5{margin-top:3rem!important}.mt-lg-auto{margin-top:auto!important}.me-lg-0{margin-right:0!important}.me-lg-1{margin-right:.25rem!important}.me-lg-2{margin-right:.5rem!important}.me-lg-3{margin-right:1rem!important}.me-lg-4{margin-right:1.5rem!important}.me-lg-5{margin-right:3rem!important}.me-lg-auto{margin-right:auto!important}.mb-lg-0{margin-bottom:0!important}.mb-lg-1{margin-bottom:.25rem!important}.mb-lg-2{margin-bottom:.5rem!important}.mb-lg-3{margin-bottom:1rem!important}.mb-lg-4{margin-bottom:1.5rem!important}.mb-lg-5{margin-bottom:3rem!important}.mb-lg-auto{margin-bottom:auto!important}.ms-lg-0{margin-left:0!important}.ms-lg-1{margin-left:.25rem!important}.ms-lg-2{margin-left:.5rem!important}.ms-lg-3{margin-left:1rem!important}.ms-lg-4{margin-left:1.5rem!important}.ms-lg-5{margin-left:3rem!important}.ms-lg-auto{margin-left:auto!important}.p-lg-0{padding:0!important}.p-lg-1{padding:.25rem!important}.p-lg-2{padding:.5rem!important}.p-lg-3{padding:1rem!important}.p-lg-4{padding:1.5rem!important}.p-lg-5{padding:3rem!important}.px-lg-0{padding-right:0!important;padding-left:0!important}.px-lg-1{padding-right:.25rem!important;padding-left:.25rem!important}.px-lg-2{padding-right:.5rem!important;padding-left:.5rem!important}.px-lg-3{padding-right:1rem!important;padding-left:1rem!important}.px-lg-4{padding-right:1.5rem!important;padding-left:1.5rem!important}.px-lg-5{padding-right:3rem!important;padding-left:3rem!important}.py-lg-0{padding-top:0!important;padding-bottom:0!important}.py-lg-1{padding-top:.25rem!important;padding-bottom:.25rem!important}.py-lg-2{padding-top:.5rem!important;padding-bottom:.5rem!important}.py-lg-3{padding-top:1rem!important;padding-bottom:1rem!important}.py-lg-4{padding-top:1.5rem!important;padding-bottom:1.5rem!important}.py-lg-5{padding-top:3rem!important;padding-bottom:3rem!important}.pb-lg-0{padding-bottom:0!important}.pb-lg-1{padding-bottom:.25rem!important}.pb-lg-2{padding-bottom:.5rem!important}.pb-lg-3{padding-bottom:1rem!important}.pb-lg-4{padding-bottom:1.5rem!important}.pb-lg-5{padding-bottom:3rem!important}}@media (min-width:1200px){.d-xl-inline{display:inline!important}.d-xl-flex{display:flex!important}.d-xl-inline-flex{display:inline-flex!important}.d-xl-none{display:none!important}.flex-xl-fill{flex:1 1 auto!important}.flex-xl-row{flex-direction:row!important}.flex-xl-column{flex-direction:column!important}.justify-content-xl-center{justify-content:center!important}.justify-content-xl-between{justify-content:space-between!important}.align-items-xl-center{align-items:center!important}.align-content-xl-center{align-content:center!important}.align-content-xl-between{align-content:space-between!important}.order-xl-0{order:0!important}.order-xl-1{order:1!important}.order-xl-2{order:2!important}.order-xl-3{order:3!important}.order-xl-4{order:4!important}.order-xl-5{order:5!important}.order-xl-last{order:6!important}.m-xl-0{margin:0!important}.m-xl-1{margin:.25rem!important}.m-xl-2{margin:.5rem!important}.m-xl-3{margin:1rem!important}.m-xl-4{margin:1.5rem!important}.m-xl-5{margin:3rem!important}.m-xl-auto{margin:auto!important}.my-xl-0{margin-top:0!important;margin-bottom:0!important}.my-xl-1{margin-top:.25rem!important;margin-bottom:.25rem!important}.my-xl-2{margin-top:.5rem!important;margin-bottom:.5rem!important}.my-xl-3{margin-top:1rem!important;margin-bottom:1rem!important}.my-xl-4{margin-top:1.5rem!important;margin-bottom:1.5rem!important}.my-xl-5{margin-top:3rem!important;margin-bottom:3rem!important}.my-xl-auto{margin-top:auto!important;margin-bottom:auto!important}.mt-xl-0{margin-top:0!important}.mt-xl-1{margin-top:.25rem!important}.mt-xl-2{margin-top:.5rem!important}.mt-xl-3{margin-top:1rem!important}.mt-xl-4{margin-top:1.5rem!important}.mt-xl-5{margin-top:3rem!important}.mt-xl-auto{margin-top:auto!important}.me-xl-0{margin-right:0!important}.me-xl-1{margin-right:.25rem!important}.me-xl-2{margin-right:.5rem!important}.me-xl-3{margin-right:1rem!important}.me-xl-4{margin-right:1.5rem!important}.me-xl-5{margin-right:3rem!important}.me-xl-auto{margin-right:auto!important}.mb-xl-0{margin-bottom:0!important}.mb-xl-1{margin-bottom:.25rem!important}.mb-xl-2{margin-bottom:.5rem!important}.mb-xl-3{margin-bottom:1rem!important}.mb-xl-4{margin-bottom:1.5rem!important}.mb-xl-5{margin-bottom:3rem!important}.mb-xl-auto{margin-bottom:auto!important}.ms-xl-0{margin-left:0!important}.ms-xl-1{margin-left:.25rem!important}.ms-xl-2{margin-left:.5rem!important}.ms-xl-3{margin-left:1rem!important}.ms-xl-4{margin-left:1.5rem!important}.ms-xl-5{margin-left:3rem!important}.ms-xl-auto{margin-left:auto!important}.p-xl-0{padding:0!important}.p-xl-1{padding:.25rem!important}.p-xl-2{padding:.5rem!important}.p-xl-3{padding:1rem!important}.p-xl-4{padding:1.5rem!important}.p-xl-5{padding:3rem!important}.px-xl-0{padding-right:0!important;padding-left:0!important}.px-xl-1{padding-right:.25rem!important;padding-left:.25rem!important}.px-xl-2{padding-right:.5rem!important;padding-left:.5rem!important}.px-xl-3{padding-right:1rem!important;padding-left:1rem!important}.px-xl-4{padding-right:1.5rem!important;padding-left:1.5rem!important}.px-xl-5{padding-right:3rem!important;padding-left:3rem!important}.py-xl-0{padding-top:0!important;padding-bottom:0!important}.py-xl-1{padding-top:.25rem!important;padding-bottom:.25rem!important}.py-xl-2{padding-top:.5rem!important;padding-bottom:.5rem!important}.py-xl-3{padding-top:1rem!important;padding-bottom:1rem!important}.py-xl-4{padding-top:1.5rem!important;padding-bottom:1.5rem!important}.py-xl-5{padding-top:3rem!important;padding-bottom:3rem!important}.pb-xl-0{padding-bottom:0!important}.pb-xl-1{padding-bottom:.25rem!important}.pb-xl-2{padding-bottom:.5rem!important}.pb-xl-3{padding-bottom:1rem!important}.pb-xl-4{padding-bottom:1.5rem!important}.pb-xl-5{padding-bottom:3rem!important}}@font-face{font-family:bootstrap-icons;src:url(fonts/bootstrap-icons.woff2?856008caa5eb66df68595e734e59580d) format("woff2"),url(fonts/bootstrap-icons.woff?856008caa5eb66df68595e734e59580d) format("woff")}

)=====";

char js[] PROGMEM = R"=====(

dunit = 0;
const GROUP_SWITCH = 1
const GROUP_HT = 2
const GROUP_MOTION =  3
sensor_category = 0;

const CBLUE = "#33c5ff"
const CYELLOW = "#FFD333"
const CRED = "#FF6D33"

sensor_data_array = [];
sensor_info = [];
sensors_name = [];

function loadSensors() {
  
  getSystemStatus();
  if( document.getElementById("lista").innerHTML == "") return;
  const xhttp = new XMLHttpRequest();
  xhttp.addEventListener('progress', handleSensorLoading);
  xhttp.open("GET", "/raw", true);
  xhttp.send();
  
  xhttp.onload = function() {
    if(this.responseText){
      clearPage();
      var sensors = this.responseText.split('\n');
      sensors.forEach( function(item) {
        AddSensorBlock(item);
      });
    }else{
      document.getElementById("lista").innerHTML = "<div class='pt-3 text-center' style='width:100%!important'><p>No sensors have been detected.</p></div>";
    }
  }
}

function loadSensorsName(){

  const xhttp = new XMLHttpRequest();
  xhttp.open("GET", "/names", true);
  xhttp.send();
  
  xhttp.onload = function() {
    if(this.responseText){
      sensors_name = [];
      var sensors = this.responseText.split('\n');
      sensors.forEach( function(item) {
        const [sid,sname] = item.split(','); 
        if( sid && sname && sname != "") sensors_name[sid] = sname.substring(0,15).toUpperCase();
      });
    }else{
      document.getElementById("lista").innerHTML = "<div class='pt-3 text-center' style='width:100%!important'><p>No sensors have been detected.</p></div>";
    }
  } 
}

function getSensorReadableName(id){

  if( sensors_name[id] && sensors_name[id].length > 1 ) return sensors_name[id];
  else return id;
}

function deleteSensor(id){

  if (confirm("Delete?")) {
    const xhttp = new XMLHttpRequest();
   xhttp.open("GET", "/delete?id="+id, true);
   xhttp.send();
  
   xhttp.onload = function() {
     if(this.responseText == "1") loadSensor(id);
     else alert('Error deleting file!');
    } 
  }
}

function recheckSDCard(id){

  const xhttp = new XMLHttpRequest();
  xhttp.open("GET", "/retry_sd", true);
  xhttp.send();
  xhttp.onload = function() {
    if(this.responseText == "1"){
      getSystemStatus();
      loadSensors();
    }
  }
}


function reboot(){
  
  if (confirm("Reboot?")) {
    const xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/reboot", true);
    xhttp.send();
    document.getElementsByTagName("main")[0].innerHTML = "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#aaa;'>restarting  ...</div>";
  }
  return false;
}

function enableReceiverOTA(){

  if (confirm("Enable Receiver OTA?")) {
    const xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rota_enable", true);
    xhttp.send();
  
    xhttp.onload = function() {
      getSystemStatus();
    }
  }
  return false;
}

function getSystemStatus(){
  
  const xhttp = new XMLHttpRequest();
  xhttp.open("GET", "/status", true);
  xhttp.send();
    
  xhttp.onload = function() {
    if(this.responseText){
      const [status_sd_card,status_mqtt,status_ota] = this.responseText.split(','); 

     if(status_sd_card == 0) document.getElementById("sdcard_status").classList.remove("d-none");
     else document.getElementById("sdcard_status").classList.add("d-none");  

     if(status_mqtt == 0) document.getElementById("mqtt_alert").classList.remove("d-none");
     else document.getElementById("mqtt_alert").classList.add("d-none");  

     if(status_ota == 0)document.getElementById("top_bar").style.backgroundColor = "#ff0000";
     else if(status_ota == 2) document.getElementById("top_bar").style.backgroundColor = "#ffbf00"; 
     else document.getElementById("top_bar").style.backgroundColor = "#33C5FF";
     
    }

  }
}

function clearList(){
  
  document.getElementById("lista").innerHTML = "";
}

function clearPage(){
  
  document.getElementById("lista").innerHTML = "";
  document.getElementById("listh").innerHTML = "";
}

function AddSensorBlock(item){

     const [sid,scategory,sstatus,stemperature,shumidity,sunit,sbattery,stimetamp] = item.split(',');  
     if(!sid) return;
     
     var perc = (sbattery - 3.3) / 0.006 | 0; 
          
     s = "";
     if(scategory==0) s = "view history"; 
     if(scategory==1 && sstatus == 1)   s = "OPEN"; 
     if(scategory==1 && sstatus == 0)   s = "CLOSED"; 
     if(scategory==3 && sstatus == 1)   s = "MOTION"; 
     if(scategory==3 && sstatus == 0)   s = "CLEAR"; 
     if(scategory==2)  s = parseFloat(stemperature).toFixed(1) + sunit;
     
     if( sunit == "°F") dunit = 1;

     if(sbattery >= 3.75)  b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery-full' viewBox='0 0 16 16'><path d='M2 6h10v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";  
     else if(sbattery >= 3.4) b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery-half' viewBox='0 0 16 16'><path d='M2 6h5v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";
     else b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery text-danger' viewBox='0 0 16 16'><path d='M0 6a2 2 0 0 1 2-2h10a2 2 0 0 1 2 2v4a2 2 0 0 1-2 2H2a2 2 0 0 1-2-2V6zm2-1a1 1 0 0 0-1 1v4a1 1 0 0 0 1 1h10a1 1 0 0 0 1-1V6a1 1 0 0 0-1-1H2zm14 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";

     if(sbattery < 3.4) bgc = "text-danger";
     else bgc = "";
       
     if(scategory==1)       icon = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-door-closed' style='margin-top:-8px' viewBox='0 0 16 16'><path d='M3 2a1 1 0 0 1 1-1h8a1 1 0 0 1 1 1v13h1.5a.5.5 0 0 1 0 1h-13a.5.5 0 0 1 0-1H3V2zm1 13h8V2H4v13z'/><path d='M9 9a1 1 0 1 0 2 0 1 1 0 0 0-2 0z'/></svg>";  
     else if(scategory==2)  icon = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-thermometer-half' style='margin-top:-8px' viewBox='0 0 16 16'><path d='M9.5 12.5a1.5 1.5 0 1 1-2-1.415V6.5a.5.5 0 0 1 1 0v4.585a1.5 1.5 0 0 1 1 1.415z'/><path d='M5.5 2.5a2.5 2.5 0 0 1 5 0v7.55a3.5 3.5 0 1 1-5 0V2.5zM8 1a1.5 1.5 0 0 0-1.5 1.5v7.987l-.167.15a2.5 2.5 0 1 0 3.333 0l-.166-.15V2.5A1.5 1.5 0 0 0 8 1z'/></svg>";
     else if(scategory==3)  icon = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-walk' style='margin-top:-8px' viewBox='0 0 320 512 '><path d='M208 96c26.5 0 48-21.5 48-48S234.5 0 208 0s-48 21.5-48 48 21.5 48 48 48zm94.5 149.1l-23.3-11.8-9.7-29.4c-14.7-44.6-55.7-75.8-102.2-75.9-36-.1-55.9 10.1-93.3 25.2-21.6 8.7-39.3 25.2-49.7 46.2L17.6 213c-7.8 15.8-1.5 35 14.2 42.9 15.6 7.9 34.6 1.5 42.5-14.3L81 228c3.5-7 9.3-12.5 16.5-15.4l26.8-10.8-15.2 60.7c-5.2 20.8.4 42.9 14.9 58.8l59.9 65.4c7.2 7.9 12.3 17.4 14.9 27.7l18.3 73.3c4.3 17.1 21.7 27.6 38.8 23.3 17.1-4.3 27.6-21.7 23.3-38.8l-22.2-89c-2.6-10.3-7.7-19.9-14.9-27.7l-45.5-49.7 17.2-68.7 5.5 16.5c5.3 16.1 16.7 29.4 31.7 37l23.3 11.8c15.6 7.9 34.6 1.5 42.5-14.3 7.7-15.7 1.4-35.1-14.3-43zM73.6 385.8c-3.2 8.1-8 15.4-14.2 21.5l-50 50.1c-12.5 12.5-12.5 32.8 0 45.3s32.7 12.5 45.2 0l59.4-59.4c6.1-6.1 10.9-13.4 14.2-21.5l13.5-33.8c-55.3-60.3-38.7-41.8-47.4-53.7l-20.7 51.5z'></path></svg>";
     else icon = "";

     if(scategory == 0) c = 'color:#dfdfdf;';
     else c = '';

     html = "<div class='col p-sm-3' onclick=\"loadSensor('"+sid+".log')\">";
     html += " <div class='pointer card mb-4 rounded-3 shadow-sm'>";
     html += "     <div class='card-header py-3 sensor_header'><p class='my-0 fw-normal'> "+getSensorReadableName(sid)+"</p></div>";
     html += "     <div class='card-body'>";
     html += "       <h2 class='card-title pricing-card-title mt-3' style='"+c+"'>"+icon+" "+s+"</h2>";
     if(scategory != 0) html += "       <ul class='list-unstyled mt-3 mb-3'><li>"+sbattery+"v  "+b+"</li><li><small>"+getFormatedDuration(stimetamp)+"</small></li></ul>";
     else html += "       <ul class='list-unstyled mt-3 mb-3'><li>&nbsp;</li><li><small style='"+c+"'>"+readableSize(stimetamp)+"</small></li></ul>";
     html += "     </div>";
     html += "   </div>";
     html += " </div>";
     
     document.getElementById("lista").innerHTML += html; 
}


function loadSensor(id) {
  
  sensor_data_array = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
  sensor_data_array["min"] = 1000;
  sensor_data_array["max"] = 0;
  sensor_info = [];
  sensor_info['filename'] = id;
  
  cursorLoading();
  const xhttp = new XMLHttpRequest();
  xhttp.addEventListener('progress', handleSensorLoading);
  xhttp.open("GET", "/sensor?id="+ id, true);
  xhttp.send();
  
  xhttp.onload = function() {
    cursorDone();
    document.getElementById("lista").innerHTML = "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#cccccc;'>loading ... 100%</div>";  
    if(this.responseText && this.responseText != "No SD card found."){
      clearPage();
      html = " <div class=''>";
      html += "     <div class='row alert mb-4' style='padding:25px!important;background-color:#33c5ff;margin-top:-27px;color:white;border-top-right-radius:0rem;border-top-left-radius:0rem;border-bottom-left-radius:0.5rem;border-bottom-right-radius:0.6rem;'><div id='icon' class='col-1'></div><div class='my-0 fw-normal col-2' style='text-align:left'>"+getSensorReadableName(id.substring(0, id.length-4))+"</div><div id='scount' class='col-4'>"+id+"</div><div id='scount' class='col-3'></div><div id='sbattery' class='col-2'></div></div><div id='sgraph'></div><div id='sdata' class='p-2' style='color:#666666'></div>";

      document.getElementById("listh").innerHTML += html; 
      var sensors = this.responseText.split('\n');
      sensors.forEach( function(item) {
        AddSensorLine(item);
        collectSensorData(item);
      });
       html = " </div>";
      document.getElementById("listh").innerHTML += html; 
      if( sensor_info['count'] > 1){
        showLatestData();
        plotSensorData();
      }else{
        document.getElementById("listh").innerHTML += "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#cccccc;'>No data</div>";
      }
    }else{
      document.getElementById("listh").innerHTML += "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#cccccc;'>No file found</div>";
    }
  }
}

function handleSensorLoading(e){

  if (e.lengthComputable)
    document.getElementById("lista").innerHTML = "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#cccccc;'>loading ... "+ parseInt((e.loaded / e.total) * 100) +"%</div>";  
}

function AddSensorLine(item){

    const [ltimestamp,lcategory,lstatus,ltemperature,lhumidity,lbattery] = item.split(',');  
    if(!ltimestamp || !lcategory || !lbattery) return;

    sensor_category = lcategory;
    sensor_info['category'] = lcategory;
    if( sensor_info['count'] > 0 ) sensor_info['count'] = sensor_info['count'] + 1;
    else sensor_info['count'] = 1;
    sensor_info['battery'] = lbattery;
    sensor_info['timestamp'] = ltimestamp;
    
    const date = new Date(ltimestamp * 1000);

     if(lcategory==1)       document.getElementById("icon").innerHTML = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-door-closed' style='margin-top:-8px' viewBox='0 0 16 16'><path d='M3 2a1 1 0 0 1 1-1h8a1 1 0 0 1 1 1v13h1.5a.5.5 0 0 1 0 1h-13a.5.5 0 0 1 0-1H3V2zm1 13h8V2H4v13z'/><path d='M9 9a1 1 0 1 0 2 0 1 1 0 0 0-2 0z'/></svg>";  
     else if(lcategory==2)  document.getElementById("icon").innerHTML = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-thermometer-half' style='margin-top:-8px' viewBox='0 0 16 16'><path d='M9.5 12.5a1.5 1.5 0 1 1-2-1.415V6.5a.5.5 0 0 1 1 0v4.585a1.5 1.5 0 0 1 1 1.415z'/><path d='M5.5 2.5a2.5 2.5 0 0 1 5 0v7.55a3.5 3.5 0 1 1-5 0V2.5zM8 1a1.5 1.5 0 0 0-1.5 1.5v7.987l-.167.15a2.5 2.5 0 1 0 3.333 0l-.166-.15V2.5A1.5 1.5 0 0 0 8 1z'/></svg>";
     else if(lcategory==3)  document.getElementById("icon").innerHTML = "<svg xmlns='http://www.w3.org/2000/svg' width='32' height='32' fill='currentColor' class='bi bi-walk' style='margin-top:-8px' viewBox='0 0 320 512 '><path d='M208 96c26.5 0 48-21.5 48-48S234.5 0 208 0s-48 21.5-48 48 21.5 48 48 48zm94.5 149.1l-23.3-11.8-9.7-29.4c-14.7-44.6-55.7-75.8-102.2-75.9-36-.1-55.9 10.1-93.3 25.2-21.6 8.7-39.3 25.2-49.7 46.2L17.6 213c-7.8 15.8-1.5 35 14.2 42.9 15.6 7.9 34.6 1.5 42.5-14.3L81 228c3.5-7 9.3-12.5 16.5-15.4l26.8-10.8-15.2 60.7c-5.2 20.8.4 42.9 14.9 58.8l59.9 65.4c7.2 7.9 12.3 17.4 14.9 27.7l18.3 73.3c4.3 17.1 21.7 27.6 38.8 23.3 17.1-4.3 27.6-21.7 23.3-38.8l-22.2-89c-2.6-10.3-7.7-19.9-14.9-27.7l-45.5-49.7 17.2-68.7 5.5 16.5c5.3 16.1 16.7 29.4 31.7 37l23.3 11.8c15.6 7.9 34.6 1.5 42.5-14.3 7.7-15.7 1.4-35.1-14.3-43zM73.6 385.8c-3.2 8.1-8 15.4-14.2 21.5l-50 50.1c-12.5 12.5-12.5 32.8 0 45.3s32.7 12.5 45.2 0l59.4-59.4c6.1-6.1 10.9-13.4 14.2-21.5l13.5-33.8c-55.3-60.3-38.7-41.8-47.4-53.7l-20.7 51.5z'></path></svg>";
     else document.getElementById("icon").innerHTML = "";
     
     html  = "<div class='row mb-0' style='font-size:0.8rem;'><div class='col-3 text-left'>"+date.toDateString()+"</div><div class='col-3 text-left'>"+date.toLocaleTimeString('en-US')+"</div>";
     if( lcategory == 1){
        if(lstatus == 0) html += "<div class='col-4 text-left'>CLOSED</div>"; 
        else html += "<div class='col-4 text-left'>OPEN</div>";       
     }
     if( lcategory == 2){
        if(lhumidity > 0){
            html += "<div class='col-2 text-left'>"+getFormatedTemperature(ltemperature,dunit) + "</div>"; 
            html += "<div class='col-2 text-left'>"+lhumidity+"%</div>";   
        }else{
            html += "<div class='col-4 text-left'>"+getFormatedTemperature(ltemperature,dunit) + "</div>"; 
        }
     } 
     if( lcategory == 3){
        if(lstatus == 1) html += "<div class='col-4 text-left'>MOTION</div>"; 
        else html += "<div class='col-4 text-left'>CLEAR</div>";     
     } 
     
     if(lbattery >= 3.75)  b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery-full' viewBox='0 0 16 16'><path d='M2 6h10v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";  
     else if(lbattery >= 3.4) b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery-half' viewBox='0 0 16 16'><path d='M2 6h5v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";
     else b = "<svg xmlns='http://www.w3.org/2000/svg' width='16' height='16' fill='currentColor' class='bi bi-battery text-danger' viewBox='0 0 16 16'><path d='M0 6a2 2 0 0 1 2-2h10a2 2 0 0 1 2 2v4a2 2 0 0 1-2 2H2a2 2 0 0 1-2-2V6zm2-1a1 1 0 0 0-1 1v4a1 1 0 0 0 1 1h10a1 1 0 0 0 1-1V6a1 1 0 0 0-1-1H2zm14 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";

     html += "<div class='col-2 text-right'>"+ b + " " + lbattery+"volt</div></div>"; 
    
     var sdata = document.getElementById("sdata");
     sdata.innerHTML = html + sdata.innerHTML; 
     if(sensor_info['count'] > 200)  sdata.removeChild(sdata.lastChild);
}


function showLatestData(){

     if(sensor_info['battery']  >= 3.75)  b = "<svg xmlns='http://www.w3.org/2000/svg' width='36' height='20' fill='currentColor' class='bi bi-battery-full' viewBox='0 0 16 16'><path d='M2 6h10v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";  
     else if(sensor_info['battery']  >= 3.4) b = "<svg xmlns='http://www.w3.org/2000/svg' width='36' height='20' fill='currentColor' class='bi bi-battery-half' viewBox='0 0 16 16'><path d='M2 6h5v4H2V6z'/><path d='M2 4a2 2 0 0 0-2 2v4a2 2 0 0 0 2 2h10a2 2 0 0 0 2-2V6a2 2 0 0 0-2-2H2zm10 1a1 1 0 0 1 1 1v4a1 1 0 0 1-1 1H2a1 1 0 0 1-1-1V6a1 1 0 0 1 1-1h10zm4 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";
     else b = "<svg xmlns='http://www.w3.org/2000/svg' width='36' height='20' fill='currentColor' class='bi bi-battery text-danger' viewBox='0 0 16 16'><path d='M0 6a2 2 0 0 1 2-2h10a2 2 0 0 1 2 2v4a2 2 0 0 1-2 2H2a2 2 0 0 1-2-2V6zm2-1a1 1 0 0 0-1 1v4a1 1 0 0 0 1 1h10a1 1 0 0 0 1-1V6a1 1 0 0 0-1-1H2zm14 3a1.5 1.5 0 0 1-1.5 1.5v-3A1.5 1.5 0 0 1 16 8z'/></svg>";
    
    document.getElementById("scount").innerHTML = sensor_info['count'] + " records <a style='color:yellow;font-size:12px;text-decoration: none;' href='#' onclick=\"deleteSensor('"+sensor_info['filename']+"');return false;\"> X</a>";
    document.getElementById("sbattery").innerHTML = b + sensor_info['battery'] + "V";   
}


function plotSensorData(){
  
    if(sensor_category == GROUP_SWITCH) plotSensorDataMotion();
    else if(sensor_category == GROUP_HT) plotSensorDataHT(); 
    else if(sensor_category == GROUP_MOTION) plotSensorDataMotion();  
}

function plotSensorDataSwitch(){}

function plotSensorDataHT(){

  html = "<div class='row m-5 mb-0' style='margin-left: 0px;margin-right: 0px;'><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;margin-left: 0px;padding-right: 0px;margin-right: 0px;'>";
  for(var i=0; i<24;i++){
    if(sensor_data_array[i] != 0) t = sensor_data_array[i];
    else t = "-";
    html += "<div class='col-1' style='font-size:8px;padding-left:0!important;padding-right:0!important;'>"+t+"</div>";  
    if(i==11)  html += "</div><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;padding-left: 0px;margin-left: 0px;margin-right: 0px;'>";
  }  
  html += "</div></div>"; 
  height = sensor_data_array["max"]-sensor_data_array["min"];
  if( height < 20) height = 20;
  html += "<div class='m-5 mb-0 mt-4'><svg id='svg' class='chart' viewBox='0 0 230 "+height+"'><polyline id='poly' fill='none' stroke='#d03535' stroke-width='0.5' points=''></polyline></svg></div>";
  html += "<div class='row m-5 mt-0' style='margin-left: 0px;margin-right: 0px;'><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;margin-left: 0px;padding-right: 0px;margin-right: 0px;'>";
  for(var i=0; i<24;i++){
    html += "<div class='col-1' style='font-size:8px;padding-left:0!important;padding-right:0!important;'>"+(i)+":00</div>";  
    if(i==11)  html += "</div><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;padding-left: 0px;margin-left: 0px;margin-right: 0px;'>";
  } 
  html += "</div></div>"; 
  document.getElementById("sgraph").innerHTML = html;
  var svg = document.getElementById('svg');
  var polyline= document.getElementById('poly');
  for(var i=0; i<23;i++){
     if( sensor_data_array[i] > 0 ){
        point = svg.createSVGPoint();
        if(i==23) point.x = i*10 - 5;
        else point.x = parseInt(5+i*9.86);
        point.y = sensor_data_array["max"] - sensor_data_array[i];
        polyline.points.appendItem(point);
     }
     
     if( true == false ){
        if(i==23) point.x = i*10 - 5;
        else point.x = parseInt(5+i*9.86);

        if( sensor_data_array["max"]-sensor_data_array["min"] <= 5 ) point.y =  sensor_data_array["max"] - sensor_data_array[i] ;
        else point.y = 20 / (sensor_data_array["max"]-sensor_data_array["min"] ) * ( sensor_data_array["max"] - sensor_data_array[i] );        
      }

  }

}

function plotSensorDataMotion(){
  
  html = "<div class='row mt-5' style='margin-left: 0px;margin-right: 0px;'><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;margin-left: 0px;padding-right: 0px;margin-right: 0px;'>";
  for(var i=0; i<24;i++){
    mid_point = (sensor_data_array["max"] - sensor_data_array["min"]) / 2 + sensor_data_array["min"];
    if( sensor_data_array[i] >= mid_point ) c = "background-color:" + CRED;
    else if( sensor_data_array[i] >= sensor_data_array["min"] ) c = "background-color:" + CYELLOW;
    else c = "";
    if(i==0) l = "border-left:solid 1px #3d568a;";
    else l = "";
    if(i==23) r = "border-right:solid 1px #3d568a;";
    else r = "";
    html += "<div class='col-1' style='padding-left:0!important;padding-right: 0!important;border-top:solid 1px #3d568a;border-bottom:solid 1px #3d568a;border-right:solid 1px #b2b7c1;"+l+r+c+"'>&nbsp;</div>";  
    if(i==11)  html += "</div><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;padding-left: 0px;margin-left: 0px;margin-right: 0px;'>";
  }  
  html += "</div></div>";

  html += "<div class='row mb-5' style='margin-left: 0px;margin-right: 0px;'><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;margin-left: 0px;padding-right: 0px;margin-right: 0px;'>";
  for(var i=0; i<24;i++){

    html += "<div class='col-1' style='font-size:8px;padding-left:0!important;padding-right:0!important;'>"+(i)+":00</div>";  
    if(i==11)  html += "</div><div class='col-6 row' style='border-left-width: 0px;border-left-style: solid;padding-left: 0px;margin-left: 0px;margin-right: 0px;'>";
  }  
  html += "</div></div>";  
  document.getElementById("sgraph").innerHTML = html;
}


function collectSensorData(item){

    if(sensor_category == GROUP_SWITCH) collectSensorDataMotion(item);
    else if(sensor_category == GROUP_HT) collectSensorDataHT(item); 
    else if(sensor_category == GROUP_MOTION) collectSensorDataMotion(item); 
}

function collectSensorDataSwitch(item){}

function collectSensorDataHT(item){
  
     const [ltimestamp,lcategory,lstatus,ltemperature,lhumidity,lbattery] = item.split(',');  
     if(!ltimestamp) return;

     var d = new Date(ltimestamp*1000);
     var current_date = new Date();
     var current_day = current_date.getDate();
     if(d.getDate() == current_day){
        tlocal = getFormatedTemperatureNoUnit(ltemperature,dunit);
        sensor_data_array[d.getHours()] = tlocal;
        if( tlocal > sensor_data_array["max"]) sensor_data_array["max"] = tlocal;
        if( tlocal < sensor_data_array["min"]) sensor_data_array["min"] = tlocal;
     }  
}

function collectSensorDataMotion(item){

     const [ltimestamp,lcategory,lstatus,ltemperature,lhumidity,lbattery] = item.split(',');  
     if(!ltimestamp) return;

     var d = new Date(ltimestamp*1000);
     var current_date = new Date();
     var current_day = current_date.getDate();
     if(d.getDate() == current_day){
        sensor_data_array[d.getHours()] += 1;   
        if( sensor_data_array[d.getHours()] > sensor_data_array["max"]) sensor_data_array["max"] = sensor_data_array[d.getHours()];
        if( sensor_data_array[d.getHours()] < sensor_data_array["min"]) sensor_data_array["min"] = sensor_data_array[d.getHours()];
     }
}

        
function getFormatedDuration(stimestamp){

  duration = Math.floor(Date.now() / 1000) - stimestamp;
  if (duration >= 86400){
    d = parseInt(duration/86400);
    if( d == 1 ) return d + " day ago";
    else return d + " days ago";
  }
  if (duration >= 3600){
    h = parseInt(duration/3600);
    if( h == 1 ) return h + " hour ago";
    else return h + " hours ago";
  }
  if (duration >= 60) {
    m = parseInt(duration/60);
    if( m == 1 ) return m + " minute ago";
    else return m + " minutes ago";    
  }
  if( duration == 1) return duration + " second ago";  
  else return duration + " seconds ago"; 
}


function getFormatedTemperature(t,u){
     
  if (u == 0 ) return (parseFloat(t).toFixed(1)) + "°C";
  else return (parseFloat(t*1.8+32).toFixed(1)) + "°F";
}

function getFormatedTemperatureNoUnit(t,u){
     
  if (u == 0 ) return parseFloat(parseFloat(t).toFixed(1));
  else return parseFloat(parseFloat(t*1.8+32).toFixed(1));
}

function readableSize(a, b, c, d, e) {
    return (b = Math, c = b.log, d = 1000, e = c(a) / c(d) | 0, a / b.pow(d, e)).toFixed(0) + '' + (e ? 'kMGTPEZY' [--e] + 'B' : 'B')
}

function cursorLoading(){
  document.body.style.cursor = 'progress';
  document.getElementById("lista").innerHTML = "<div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#cccccc;'>loading ...</div>";
}

function cursorDone(){
  document.body.style.cursor = 'default';
}

)=====";


char html_saved[] PROGMEM = R"=====(

  <!DOCTYPE html><html lang='en'><head><meta name='viewport' content='width=device-width, initial-scale=1, user-scalable=no'/>
  <title>The Hub by MrDIY</title>
  <link rel="icon" type="image/png" sizes="16x16" href="data:image/x-icon;base64,AAABAAEAEBAAAAEAIABoBAAAFgAAACgAAAAQAAAAIAAAAAEAIAAAAAAAQAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIdUOc6IVTvpiFU654hVOuaIVTvkiVU74IdUOsqFUDaMAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACIVDvli1c9/4pWPf+KVj3/ilY9/4pXPf+LVz3/jVk+/4lWPPaBSS5pAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgk064oVRPf+EUDz/hFA8/4RQPP98Rz3/fUk8/4VRPP+KVzz/jVk+/4ROMXwAAAAA/8s1///LNf//yzX//8s1///KM///yjL//8oy///KMv//yjL//8ky//C4Nf+wfjr/f0o8/4pWPP+LVz3/AAAAAP/FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xjP//8wy/76LOf+DTzz/jFg9/4ZTOLX/xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xzP/f0s8/4pWPP+IVTvj/8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8oy/6JwO/+HUzz/ilY88//FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///KMv+fbTv/h1Q8/4pWPPP/xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///GM///xTP/fUg8/4pWPP+JVjri/8Yz///GM///xjP//8Yz///GM///xjP//8Yz///GM///xjP//8Yz///HM///yzL/sX46/4RRPP+MWD3/h1I4sf/GMvT/xjL0/8Yy9P/FMvP4wDP99740//e+NP/3vjT/9740//O6NP/dpzf/m2k7/4JOPP+KVjz/iVY8/wAAAAAAAAAAAAAAAAAAAAAAAAAAd0A74X5IPf98Rzz/fEc8/3xHPP99SDz/gEw8/4dTPP+LVz3/jFg9/4FKL2sAAAAAAAAAAAAAAAAAAAAAAAAAAIhVOuaMWD7/i1c9/4tXPf+LVz3/i1c9/4xYPf+OWT//iFQ75XxDJ0gAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACHUji2iFQ6zohTOc2HVDnMh1M5yodUOsaGUjerf0YqVAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA//8AAPAPAADwAwAA8AEAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAQAA8AEAAPADAADwDwAA//8AAA==" />
  <meta content="text/html;charset=utf-8" http-equiv="Content-Type">
  <meta content="utf-8" http-equiv="encoding">
  <link rel="stylesheet" href="bootstrap.css">
  <link rel="stylesheet" href="main.css">
  </head><body>
  <div style='position:absolute;top:0px;height:5px;width:100%;background-color:#33C5FF;'></div>
    <div class="container py-3">
  <header>
    <div class="d-flex flex-column flex-md-row align-items-center pb-3 mb-4 border-bottom">
      <a href='/' class='d-flex align-items-center text-dark text-decoration-none'><span class='fs-4 logo'></span></a><span class='fs-4'>Configuration</span>
      <nav class="d-inline-flex mt-2 mt-md-0 ms-md-auto">
        <a class='me-3 py-2 text-dark text-decoration-none' href='/'>
          <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-house-door" viewBox="0 0 16 16">
            <path d="M8.354 1.146a.5.5 0 0 0-.708 0l-6 6A.5.5 0 0 0 1.5 7.5v7a.5.5 0 0 0 .5.5h4.5a.5.5 0 0 0 .5-.5v-4h2v4a.5.5 0 0 0 .5.5H14a.5.5 0 0 0 .5-.5v-7a.5.5 0 0 0-.146-.354L13 5.793V2.5a.5.5 0 0 0-.5-.5h-1a.5.5 0 0 0-.5.5v1.293L8.354 1.146zM2.5 14V7.707l5.5-5.5 5.5 5.5V14H10v-4a.5.5 0 0 0-.5-.5h-3a.5.5 0 0 0-.5.5v4H2.5z"/>
        </svg>        
        </a>
      </nav>
    </div>
  </header>
  <main>
     <div class='col-12 mt-5' style='width:100%!important;text-align:center;color:#666666;'>
        <p>Your settings have been updated!<br />You might need to <a href='/' onclick='return reboot();'>restart</a> the hub!</p>
     </div> 
  </main>
  </body>
  </html>

)=====";


char html_main[] PROGMEM = R"=====(

  <!DOCTYPE html><html lang='en'><head><meta name='viewport' content='width=device-width, initial-scale=1, user-scalable=no'/>
  <title>The Hub by MrDIY</title>
  <link rel="icon" type="image/png" sizes="16x16" href="data:image/x-icon;base64,AAABAAEAEBAAAAEAIABoBAAAFgAAACgAAAAQAAAAIAAAAAEAIAAAAAAAQAQAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAIdUOc6IVTvpiFU654hVOuaIVTvkiVU74IdUOsqFUDaMAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACIVDvli1c9/4pWPf+KVj3/ilY9/4pXPf+LVz3/jVk+/4lWPPaBSS5pAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAgk064oVRPf+EUDz/hFA8/4RQPP98Rz3/fUk8/4VRPP+KVzz/jVk+/4ROMXwAAAAA/8s1///LNf//yzX//8s1///KM///yjL//8oy///KMv//yjL//8ky//C4Nf+wfjr/f0o8/4pWPP+LVz3/AAAAAP/FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xjP//8wy/76LOf+DTzz/jFg9/4ZTOLX/xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xzP/f0s8/4pWPP+IVTvj/8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8oy/6JwO/+HUzz/ilY88//FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///KMv+fbTv/h1Q8/4pWPPP/xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///FM///xTP//8Uz///GM///xTP/fUg8/4pWPP+JVjri/8Yz///GM///xjP//8Yz///GM///xjP//8Yz///GM///xjP//8Yz///HM///yzL/sX46/4RRPP+MWD3/h1I4sf/GMvT/xjL0/8Yy9P/FMvP4wDP99740//e+NP/3vjT/9740//O6NP/dpzf/m2k7/4JOPP+KVjz/iVY8/wAAAAAAAAAAAAAAAAAAAAAAAAAAd0A74X5IPf98Rzz/fEc8/3xHPP99SDz/gEw8/4dTPP+LVz3/jFg9/4FKL2sAAAAAAAAAAAAAAAAAAAAAAAAAAIhVOuaMWD7/i1c9/4tXPf+LVz3/i1c9/4xYPf+OWT//iFQ75XxDJ0gAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAACHUji2iFQ6zohTOc2HVDnMh1M5yodUOsaGUjerf0YqVAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA//8AAPAPAADwAwAA8AEAAAABAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAQAA8AEAAPADAADwDwAA//8AAA==" />
  <meta content="text/html;charset=utf-8" http-equiv="Content-Type">
  <meta content="utf-8" http-equiv="encoding">
  <link rel="stylesheet" href="bootstrap.css">
  <link rel="stylesheet" href="main.css?v=7">
  </head>
  <body>
  <div id="top_bar" style='position:absolute;top:0px;height:5px;width:100%;background-color:#33C5FF;'></div>
  <div class="container py-3">
  <header>
    <div class="d-flex flex-column flex-md-row align-items-center pb-3 mb-4 border-bottom">
      <a href="/" class="d-flex align-items-center text-dark text-decoration-none"><span class="fs-4 logo"></span></a><span class="fs-4"  onclick="loadSensors();return false;">Sensors</span>
      <nav class="d-inline-flex mt-2 mt-md-0 ms-md-auto">
      <span class="me-3 py-2 me-4 text-danger" id="rota_status"></span>
        <span class="me-3 py-2 text-dark text-decoration-none d-none"  style="cursor:pointer;" onclick="recheckSDCard();return false;" id="sdcard_status">
             <svg viewBox="0 0 24 24" style="width:16px;height:16px;color: #df1919;">
                <path fill="currentColor" d="M8,2A2,2 0 0,0 6,4V11L4,13V20A2,2 0 0,0 6,22H18A2,2 0 0,0 20,20V4A2,2 0 0,0 18,2H8M9,4H11V8H9V4M12,4H14V8H12V4M15,4H17V8H15V4Z"></path>
            </svg>
        </span>
        <a class="me-3 py-2 text-dark text-decoration-none" href="/config">
             <svg xmlns="http://www.w3.org/2000/svg" width="16" height="16" fill="currentColor" class="bi bi-gear" viewBox="0 0 16 16">
              <path d="M8 4.754a3.246 3.246 0 1 0 0 6.492 3.246 3.246 0 0 0 0-6.492zM5.754 8a2.246 2.246 0 1 1 4.492 0 2.246 2.246 0 0 1-4.492 0z"/>
              <path d="M9.796 1.343c-.527-1.79-3.065-1.79-3.592 0l-.094.319a.873.873 0 0 1-1.255.52l-.292-.16c-1.64-.892-3.433.902-2.54 2.541l.159.292a.873.873 0 0 1-.52 1.255l-.319.094c-1.79.527-1.79 3.065 0 3.592l.319.094a.873.873 0 0 1 .52 1.255l-.16.292c-.892 1.64.901 3.434 2.541 2.54l.292-.159a.873.873 0 0 1 1.255.52l.094.319c.527 1.79 3.065 1.79 3.592 0l.094-.319a.873.873 0 0 1 1.255-.52l.292.16c1.64.893 3.434-.902 2.54-2.541l-.159-.292a.873.873 0 0 1 .52-1.255l.319-.094c1.79-.527 1.79-3.065 0-3.592l-.319-.094a.873.873 0 0 1-.52-1.255l.16-.292c.893-1.64-.902-3.433-2.541-2.54l-.292.159a.873.873 0 0 1-1.255-.52l-.094-.319zm-2.633.283c.246-.835 1.428-.835 1.674 0l.094.319a1.873 1.873 0 0 0 2.693 1.115l.291-.16c.764-.415 1.6.42 1.184 1.185l-.159.292a1.873 1.873 0 0 0 1.116 2.692l.318.094c.835.246.835 1.428 0 1.674l-.319.094a1.873 1.873 0 0 0-1.115 2.693l.16.291c.415.764-.42 1.6-1.185 1.184l-.291-.159a1.873 1.873 0 0 0-2.693 1.116l-.094.318c-.246.835-1.428.835-1.674 0l-.094-.319a1.873 1.873 0 0 0-2.692-1.115l-.292.16c-.764.415-1.6-.42-1.184-1.185l.159-.291A1.873 1.873 0 0 0 1.945 8.93l-.319-.094c-.835-.246-.835-1.428 0-1.674l.319-.094A1.873 1.873 0 0 0 3.06 4.377l-.16-.292c-.415-.764.42-1.6 1.185-1.184l.292.159a1.873 1.873 0 0 0 2.692-1.115l.094-.319z"/>
            </svg>
        </a>
      </nav>
    </div>
  </header>
  <main>
     <div id="mqtt_alert" role="alert" class="alert alert-danger mb-4 d-none">The hub is not connected to the MQTT server</div>
     <div class="row row-cols-1 row-cols-md-3 row-cols-lg-4 row-cols-xl-5 text-center" id="lista"><div class="col-12 mt-5" style="width:100%!important;text-align:center;color:#cccccc;">loading ...</div></div>
     <div class="row text-center" id="listh"></div> 
  </main>
  </body>
     <script src="main.js?v=12"></script><script>loadSensorsName();loadSensors();</script>
  </html>

  )=====";
