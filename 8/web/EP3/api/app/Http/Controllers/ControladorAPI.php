<?php

namespace App\Http\Controllers;

use GuzzleHttp\Client;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Log;

class ControladorAPI extends Controller
{
    public function buscar(Request $request)
    {
        $busqueda = $request->input('busqueda');

        $contenido = sprintf("%s%s%s", "https://http.cat/",  $busqueda, ".jpg");

        Log::info($busqueda);
        Log::info($contenido);

        return view('api_home', ['resultado' => $contenido]);
    }

}
