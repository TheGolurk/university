<?php

use App\Http\Controllers\ControladorAPI;
use Illuminate\Support\Facades\Route;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider and all of them will
| be assigned to the "web" middleware group. Make something great!
|
*/

Route::get('/', function () {
    return view('api_home');
})->name("api_home");


Route::get('/', [ControladorAPI::class, 'buscar'])->name("get_api_home");

// Route::get('/buscar', [ControladorAPI::class], 'buscar');

