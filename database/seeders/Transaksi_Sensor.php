<?php

namespace Database\Seeders;

use Illuminate\Database\Seeder;
use Illuminate\Support\Facades\DB;

class Transaksi_Sensor extends Seeder
{
    public function run()
    {
        DB::table('transaksi_sensor')->insert([
            'nama_sensor' => 'Sensor B',
            'nilai1' => 87,
            'nilai2' => 176,
            'created_at' => now(),
            'updated_at' => now(),
        ]);
    }
}
