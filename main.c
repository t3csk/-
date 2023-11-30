#include <stdio.h>

typedef struct
{
    char name[ 100 ];
    int speed, power, stamina, guts, wise;
} parameter;

float average( int k, int l, int m, int n, int o );

int main( void )
{
    parameter n = { 0, 0, 0, 0, 0 };
    int a,b,c,d,e,f,g,h,i,j;
    float ave;

    printf( "名前を入力してください \n" );
    scanf( "%s", n.name );
    
    printf( " 育成スタート\n" );
    printf( " すぐに死んでしまうので気を付けよう \n" );
    printf( "選んだ数字を入力してね \n" );
    
    printf( "1周目 \n" );
    printf( "1.学校に行く, 2.公園に行く , 3.図書館に行く \n" );
    scanf( "%d", &a );
    switch ( a )
    {
    case 1:
    printf( "学校に行った \n" );
    printf( " スピード + 5, パワー + 5, スタミナ + 5, ガッツ + 5, 知能 + 5 \n" );
    n.speed += 5, n.power += 5, n.stamina += 5, n.guts += 5, n.wise += 5;
    break;

    case 2:
    printf( " 公園にいった \n" );
    printf( " パワー　+ 10, スタミナ + 10 \n" );
    n.power += 10, n.stamina += 10;
    break;
    
    case 3:
    printf( " 図書館に行った \n" );
    printf( " 知能 + 20 \n" );
    n.wise += 20;
    break;
    }
    
    printf( "イベント発生 \n" );
    printf( " 仲間とトレーニングをした \n" );
    do{
        n.power += 10;
    }while( n.power < 15 );
    
    printf( " 二週目 \n" );
    printf( "1.花見に行く, 2.筋トレをする, 3.家でゲームをする \n" );
    scanf( "%d", &b );
    switch ( b )
    {
    case 1:
    printf( "花見に行った \n" );
    printf( "スピード + 5, パワー + 5, スタミナ + 5, ガッツ + 5, 知能 + 5 \n" );
    n.speed += 5, n.power += 5, n.stamina += 5, n.guts += 5, n.wise += 5;
    break;
    
    case 2:
    printf( "筋トレをした \n" );
    printf( "パワー + 20 \n" );
    n.power += 20;
    break;

    case 3:
    printf( "家でゲームをした \n" );
    break;
    }

    if( n.stamina < 1 )
    {
        printf( "スタミナがなく死んでしまった \n" );
        printf( "育成失敗 \n" );
        return 1;
    }

    printf( "3周目 \n" );
    printf( "1.ショッピングに出かける , 2.ランニングをする , 3.一日中寝る \n" );
    scanf( "%d", &c );
    switch ( c )
    {
    case 1:
    printf( "ショッピングに出かけた \n" );
    printf( "スピード + 10, スタミナ + 10 \n" );
    n.speed += 10, n.stamina += 10;
    break;

    case 2:
    printf( "ランニングをした \n" );
    printf( "スタミナ + 10, ガッツ + 10 \n" );
    n.stamina += 10, n.guts += 10;
    break;

    case 3:
    printf( "家で一日中寝た \n" );
    break;
    }

   
    printf( "4周目 \n" );
    printf( "1.映画を見に行く , 2.本を読む , 3.テニスをする \n" );
    scanf( "%d", &d );
    switch ( d )
    {
    case 1:
    printf( "映画を見た \n" );
    printf( "ガッツ + 10, 知能 + 10 \n" );
    n.guts += 10, n.wise += 10;
    break;

    case 2:
    printf( "本を読んだ \n" );
    printf( "知能 + 20 \n" );
    n.wise += 20;
    break;

    case 3:
    printf( "テニスをした \n" );
    printf( "スピード + 5, パワー + 5, スタミナ + 5, ガッツ + 5, 知能 + 5 \n" );
    n.speed += 5, n.power += 5, n.stamina += 5, n.guts += 5, n.wise += 5;
    break;
    }

    if( n.wise > 10 )
    {
        printf( "イベント発生 \n" );
        printf( "テストでいい点を取って、ご褒美を貰った \n" );
        printf( "スピード + 5, パワー + 5, スタミナ + 5, ガッツ + 5, 知能 + 5 \n" );
         n.speed += 5, n.power += 5, n.stamina += 5, n.guts += 5, n.wise += 5;
    }
    else
    {
        printf( "知能が足りず死んでしまった \n" );
        printf( "育成失敗\n" );
        return 1;
    }

    printf( "5周目 \n" );
    printf( "1.お祭りに行く , 2.サマーキャンプに参加する , 3.家で涼む \n" );
    scanf( "%d", &e );
    switch ( e )
    {
    case 1:
    printf( "お祭りに行った \n" );
    printf( "スピード + 10, パワー + 10, スタミナ + 10 \n" );
    n.speed += 10, n.power += 10, n.stamina += 10;
    break;

    case 2:
    printf( "サマーキャンプに参加した \n" );
    printf( "パワー + 10, スタミナ + 10, ガッツ + 10 \n" );
    n.power += 10, n.stamina += 10, n.guts += 10;
    break;

    case 3:
    printf( "家で涼む \n" );
    break;
    }

    if( n.power < 30 )
    {
        printf( "パワーが足りず死んでしまった \n" );
        printf( "育成失敗 \n" );
        return 1;
    }

    printf( "6周目 \n" );
    printf( "1.英語の勉強をする , 2.トレーニングをする , 3.町に遊びに行く \n" );
    scanf( "%d", &f );
    switch ( f )
    {
    case 1:
    printf( "英語の勉強をした \n" );
    printf( "知能 + 30 \n" );
    n.wise += 30;
    break;

    case 2:
    printf( "トレーニングをした \n" );
    printf( "スピード + 10, パワー + 10, スタミナ + 10, ガッツ + 5 \n" );
    n.speed += 10, n.power += 10, n.stamina += 10, n.guts += 5;
    break;

    case 3:
    printf( "町に遊びに行った \n" );
    printf( "スタミナ + 10 \n" );
    n.stamina += 10;
    break;
    }

    if( n.speed < 20 )
    {
        printf( "スピードが足りず死んでしまった \n" );
        printf( "育成失敗 \n" );
        return 1;
    }

    printf( "最終週\n" );
    printf( "1.一緒にショッピングに行く , 2.一緒に運動する , 3.一緒にゲームをする \n" );
    scanf( "%d", &g );
    switch ( g )
    {
    case 1:
    printf( "一緒にショッピングに行った \n" );
    printf( " スタミナ + 15, ガッツ + 15, 知能 + 15 \n" );
    n.stamina += 15, n.guts += 15, n.wise += 15;
    break;

    case 2:
    printf( "一緒に運動した \n" );
    printf( "スピード + 15, パワー + 15, スタミナ + 15 \n" );
    n.speed += 15, n.power += 15, n.stamina += 15;
    break;

    case 3:
    printf( "一緒にゲームをした \n" );
    printf( "スピード + 10, パワー + 10, スタミナ + 10, ガッツ + 10, 知能 + 10 \n" );
    n.speed += 10, n.power += 10, n.stamina += 10, n.guts += 10, n.wise += 10;
    break;
    }
    
    printf( "おめでとう!! \n" );
    printf( "立派に成長しました \n" );

    ave = average( n.speed, n.power, n.stamina, n.guts, n.wise );
    
    printf( "育成完了!! \n" );
    printf( "育成結果 \n" );
    printf( "名前 %c, スピード %d, パワー %d, スタミナ %d, ガッツ %d, 知能 %d, 平均能力値 %f \n", n.name, n.speed, n.power, n.stamina, n.guts, n.wise, ave );
    
    printf( "育成結果をファイルに出力しました \n" );
    FILE* fp = fopen( "kekka.txt", "w" );
	fprintf( fp, "名前　%s, スピード %d, パワー %d, スタミナ %d, ガッツ %d, 知能 %d, 平均能力値 %f", n.name, n.speed, n.power, n.stamina, n.guts, n.wise, ave  );
	fclose( fp );
    return 0;
}

float average( int k, int l, int m, int n, int o )
{
    return ( ( k + l + m + n + o ) / 5 );
}

