// Code of ShenZhou
// Room: /beijing/yiyantang.c

#include "ansi.h"
inherit ROOM;

void create()
{
    set("short", HIB"一言堂"NOR);
    set("long", @LONG
这里就是天下闻名的一言堂，独此一家，别无分号。这里的货好，价钱也不
便宜。正所谓：「皇帝女儿不愁嫁」。靠墙立着一排货架 (shelf)。八仙桌旁，
一个精瘦的家伙倒在太师椅上，擎着一支长长的旱烟管，一边晃悠着二郎腿，口
里还哼哼着小曲儿，看起来就是掌柜的了。桌上有一壶茶。一个伙计正趴在柜台
上打盹。柜台上贴着一张发黄的价目表(sign)。
LONG
    );

    set("item_desc", ([
            "shelf" : "货架上空荡荡的，看不到什么东西。\n",
            "sign" : "
		童叟无欺 言不二价


	五两黄金(gold)：\t          五点贡献度
	舍利子(slz)：\t           四十点贡献度
	菩提子(ptz)：\t           五十点贡献度
	九转还魂丹(9dan)：\t  两百五十点贡献度
	一次正常死亡(death)：\t   两百点贡献度
	一点先天容貌(rongmao)：\t 四百点贡献度
	一点先天福缘(fuyuan)：\t  六百点贡献度
	一点臂力(bili)：\t        两千点贡献度
	一点悟性(wuxing)：\t      两千点贡献度
	一点根骨(gengu)：\t       两千点贡献度
	一点身法(shenfa)：\t      两千点贡献度
	破例丹(pldan)：\t         两千点贡献度
	九阴第一卷权限(9yin1)：\t 两千点贡献度
	九阴第二卷权限(9yin2)：\t 四千点贡献度
	九阴第三卷权限(9yin3)：\t 六千点贡献度
	
	贡献度的兑换方法：
	exchange xxx  说明：xxx 为括号内的内容
	如：兑换 gold，即 exchange gold\n",
    ]));

    set("exits", ([
            "south" : __DIR__"changanjie_w",
    ]));

	set("objects", ([
		"/d/beijing/npc/yythuoji" : 1,
	]));

    set("no_fight", "1");
    set("no_steal", "1");
    set("cost", 0);
    //set("day_shop", 1);
    setup();
}

//void init()
//{
//    add_action( "exchange", "exchange" );
//}

int exchange( string arg )
{
    object me = this_player();   
    object obj; 
    int gxd=0, temp;    
    if ( !arg )
        return notify_fail( "你要用贡献度换什么？\n" );
    gxd = me->query( "shenzhou/pts" );
    if ( !gxd )
        return notify_fail( "你对神州没有贡献。\n" );   
    switch( arg )
    {
    case "gold":
        if ( gxd > 4 )
        {
           obj = new ( "/clone/money/gold" );
           obj->set_amount( 5 );
           obj->move( me );
           gxd = gxd - 5;
           me->set( "shenzhou/pts", gxd );
           tell_object( me, "你得到5两黄金.\n" );           
           return 1;
        }
        break;
    case "slz":
        if ( gxd > 39 )
        {
            obj = new ( "/clone/drug/sheli-zi" );
            obj->move( me );
            gxd = gxd - 40;
            me->set( "shenzhou/pts", gxd );
            tell_object( me, "你得到一个舍利子。\n" );
            return 1;
        }
        break;
    case "ptz":
        if ( gxd > 49 )
        {
            obj = new ( "/clone/drug/puti-zi" );
            obj->move( me );
            gxd = gxd - 50;
            me->set( "shenzhou/pts", gxd );
            tell_object( me, "你得到一个菩提子。\n" );
            return 1;
        }    
        break;
    case "9dan":
        if ( gxd > 249 )
        {
            obj = new ( "/clone/wiz/jiuzhuan" );
            obj->move( me );
            gxd = gxd - 250;
            me->set( "shenzhou/pts", gxd );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"因守卫神州有功，被天赐一枚九转还魂丹。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"因守卫神州有功，被天赐一枚九转还魂丹。\n" NOR );             
            return 1;
        }     
        break;           
    case "pldan":
        if ( gxd > 1999 )
        {
            obj = new ( "/clone/drug/pldan" );
            obj->move( me );
            gxd = gxd - 2000;
            me->set( "shenzhou/pts", gxd );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"连闯九道天关，进入通天塔内，得到了一枚破立丹。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"连闯九道天关，进入通天塔内，得到了一枚破立丹。\n" NOR );             
            return 1;
        }     
        break;    
    case "bili":
        if ( gxd > 1999 )
        {
            gxd = gxd - 2000;
            me->set( "shenzhou/pts", gxd );
            me->add( "str", 1 );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"路遇神仙，仙奖其行，从此臂力大涨。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"路遇神仙，仙奖其行，从此臂力大涨。\n" NOR );             
            return 1;
        }     
        break;        
    case "wuxing":
        if ( gxd > 1999 )
        {
            gxd = gxd - 2000;
            me->set( "shenzhou/pts", gxd );
            me->add( "int", 1 );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"因为神州出谋划策，使其学识大为突飞猛进。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"因为神州出谋划策，使其学识大为突飞猛进。\n" NOR );             
            return 1;
        }     
        break;
    case "gengu":
        if ( gxd > 1999 )
        {
            gxd = gxd - 2000;
            me->set( "shenzhou/pts", gxd );
            me->add( "con", 1 );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"因护神州龙脉有功，神仙亲授传功，功力大进。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"因护神州龙脉有功，神仙亲授传功，功力大进。\n" NOR );             
            return 1;
        }     
        break;
   case "shenfa":
        if ( gxd > 1999 )
        {
            gxd = gxd - 2000;
            me->set( "shenzhou/pts", gxd );
            me->add( "dex", 1 );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"得世外高人亲传身法秘诀，习得一身高超轻功。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"得世外高人亲传身法秘诀，习得一身高超轻功。\n" NOR );             
            return 1;
        }     
        break;
    case "roumao":
        if ( gxd > 399 )
        {
            /*if ( temp = me->query( "per" ) > 29 (
                return notify_fail( "你已经足够美了。\n" );*/
            gxd = gxd - 400;
            me->set( "shenzhou/pts", gxd );
            me->add( "per", 1 );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"的行为感动了天上专司容貌的神仙，亲传其永葆青春之术。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"的行为感动了天上专司容貌的神仙，亲传其永葆青春之术。\n" NOR );             
            return 1;
        }     
        break;                                
    case "fuyuan":
        if ( gxd > 599 )
        {
            /*if ( temp = me->query( "per" ) > 29 (
                return notify_fail( "你已经足够美了。\n" );*/
            gxd = gxd - 600;
            me->set( "shenzhou/pts", gxd );
            me->add( "kar", 1 );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"因其德行深厚，故而与仙为友，被世人视为大福大贵的象征。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"因其德行深厚，故而与仙为友，被世人视为大福大贵的象征。\n" NOR );             
            return 1;
        }     
        break;    
    case "death":
        if ( gxd > 199 )
        {
            /*if ( temp = me->query( "per" ) > 29 (
                return notify_fail( "你已经足够美了。\n" );*/
            gxd = gxd - 200;
            me->set( "shenzhou/pts", gxd );
            me->add( "death_times", 1 );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"被地府冥王奉为坐上佳宾，从而修得举世无双的天魔解体大法。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"被地府冥王奉为坐上佳宾，从而修得举世无双的天魔解体大法。\n" NOR );             
            return 1;
        }     
        break;       
    case "9yin1":
        if ( gxd > 1999 )
        {
            /*if ( temp = me->query( "per" ) > 29 (
                return notify_fail( "你已经足够美了。\n" );*/
            gxd = gxd - 2000;
            me->set( "shenzhou/pts", gxd );
            me->set( "9yin", "granted1" );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"闯入九龙阴潭得到了九阴真经第一卷，据说是由神仙为其指路。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"闯入九龙阴潭得到了九阴真经第一卷，据说是由神仙为其指路。\n" NOR );             
            return 1;
        }     
        break;     
    case "9yin2":
        if ( gxd > 3999 )
        {
            gxd = gxd - 4000;
            me->set( "shenzhou/pts", gxd );
            me->set( "9yin", "granted2" );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"击败火、炎、暴神龙三守卫，得到了九阴真经第二卷。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"击败火、炎、暴神龙三守卫，得到了九阴真经第二卷。\n" NOR );             
            return 1;
        }     
        break;     
    case "9yin3":
        if ( gxd > 5999 )
        {
            gxd = gxd - 6000;
            me->set( "shenzhou/pts", gxd );
            me->set( "9yin", "granted3" );
            shout( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"被神仙请入仙界，有了修习天下最至高无尚神功的机会。\n" NOR ); 
            write( HIM "【谣言】某人：听说"HIC + me->query( "name" ) + HIM"被神仙请入仙界，有了修习天下最至高无尚神功的机会。\n" NOR );             
            return 1;
        }     
        break;  
    default:                           
        return notify_fail( "你要换什么？\n" );
    }
    return notify_fail( "你的贡献度不够换这个。\n" );
}
