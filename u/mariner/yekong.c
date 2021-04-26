#include <ansi.h>
inherit F_CLEAN_UP;
inherit ROOM;

string *color = ({
    RED, GRN, YEL, BLK, MAG, BLU, CYN, WHT, 
    HIR, HIG, HIY, HIB, HIM, HIC, HIW, });
string *color1 = ({
    RED, HIG, HIM, MAG, HIC, HIW, 
    });

void input_number(string arg);
void show_emote(string* arg,string text);

string *pic = ({ @TEXT
        __   __
       /  \./  \/\_
   __{^\_ _}_   )  }/^\
  /  /\_/^\._}_/  //  /
 (  (__{(@)}\__}.//_/__A____A_______A_____A_____A_____A___A___A______
  \__/{/(_)\_}  )\\ \\---v-----V-----V---Y--v----Y----v---V-----v---
    (   (__)_)_/  )\ \>
     \__/     \__/\/\/
        \__,--'


TEXT,
@TEXT
 .        *                  . . . .  .   .  + .
            "You Are Here" .   .  +  . . .
.                 |      .  .   .    .    . .
                  |     .    .    . +.    +  .
                 \|/            .       .   . .
        . .       V          .    * . . .  .  +   .
           +     $BLINK$¡î$NOR$           .   .      +
                            .       . +  .+. .
  .                      .     . + .  . .     .      .
           .      .    .     . .   . . .
      *             .    . .  +    .  .           .
          .     .    .  +   . .  *  .       .
               . + .  .  .  .. +  .
.      .  .  .  *   .  *  . +..  .            *
 .      .   . .   .   .   . .  +   .    .            +
TEXT,
@TEXT
 ..           .           .        .     .   .
  *     \     |   /               + . :      *   .            .    *
  .   ---   /    \   ---       .     .   . .     .     *       .
   .       | ~  ~ |        .        . . . .  .   .  + .
      ---   \__O_/   ---         :     .   .  +  . . .
     .      /  |    .  . .     . .   .   .   . .   +  .     +
   .   *  . .      . .    . .  +    .  ...     - O -. .
          .     . + .  .  .  .. +  ..       . / |
 ..      .  .  .  *   .  *  . +..  .            *
  .      .   . .   .   .   . .  +   .    .            +

  .      .   . .   .   .   . .  +   .    .            +

                                   .&______~*@*~______&.           *
                                 "w/%%%%%%%%%%%%%%%%%%%\w"        ***
      __/M__                    p-p_|__|__|_____|__|__|_q-q      **Y**
 ____|O_^_O|___________________[EEEEM==M==MM===MM==M==MEEEE]-__....|....

    £Ä£Ï £Ù£Ï£Õ £Æ£Å£Å£Ì £Ô£È£Å £Ì£Ï£Ö£Å £Ô£Ï£Î£É£Ç£È£Ô£¿
TEXT,
@TEXT

             * *   * * *   * *
            *    *    *  *    *
        <========     *==     *==<<<<<<
             *       *       *
               *   *   *   *
                 *       *


TEXT,
 });

void create()
{
        set("short", HIC"Ò¹  ¿Õ"NOR);
        set("long", @LONG

[1;34m    .   . ¡ï  *   ¡î   .    ¡ï         .    *       ¡î     . 
       .      .    [1;36m[5m¡î[2;37;0m[1;34m     .    .  [1;36m[5m¡î[2;37;0m[1;34m.    [1;36m[5m¡ï[2;37;0m[1;34m        .    
 .   .  .   [1;36m[5m¡ï[2;37;0m[1;34m       ¡î   .     . .    .        .    [1;36m[5m¡î[2;37;0m[1;34m  
    .           ¡î          ¡ï               ¡î            .[2;37;0m




[1;34m        ¾ÍÏò[1;36m[5mÁ÷ÐÇ[2;37;0m[1;34mÐí¸öÐÄÔ¸ ÈÃ[1;35mÄã[1;34mÖªµÀ[33mÎÒ[1;31m[5m°®[2;37;0m[1;35mÄã[2;37;0m

LONG
        );
    set("no_clean_up", 0);
    set( "invalid_startroom", 1 );
    set("exits", ([
            "down"  : "/u/mariner/musicroom2",
    ]));
    set("no_steal", 1); 
    set("no_sleep_room", "1"); 
    setup();
}

void init()
{
    object mariner = find_player( "mariner" );
    if ( objectp( mariner ) )
        tell_object( mariner, this_player()->query( "id" ) + " entered yekong room.\n" );
    add_action( "Wish", "wish" );
}

int Wish(string arg)
{
    object male = this_player(), me = this_player(), female;
    string id1, id2, name1, name2;
    int times;
    id1 = male->query( "id" );
    times = me->query_temp( "wishlove" );
    if ( times )
        return notify_fail( "±ð¼±£¬ÂýÂýÀ´£¡\n" );
    this_player()->set_temp( "wishlove", 1 );
    call_out( "remove_wish", 2, me );
    if( !arg || sscanf(arg, "love %s", id2) != 1 )
    {
        this_player()->set( "wishlove", times );
        return notify_fail("Ö¸Áî¸ñÊ½£ºwish love id\n");
    }  
        
    if ( male->query("gender") != "ÄÐÐÔ" )
    {
        female = this_player();
        male = present( id2, environment( me ));
    }
    else
        female = present( id2, environment( me ));
        
    if( !male || !female || !userp( male ) || !userp( female) )
    {
        this_player()->set( "wishlove", times );
        return notify_fail("ÕâÀïÃ»ÓÐÕâ¸öÈËÅ¶~~\n");
    }
    
    if ( ! living( male ) || ! living (female) )
        return notify_fail("¿´Çå³þµã£¬ÄÇ²»ÊÇ»îµÄ¡£\n");
    if(( male->query("gender") != "ÄÐÐÔ" &&  male->query("gender") != "ÐÛÐÔ")
        ||(female->query("gender") != "Å®ÐÔ" &&female->query("gender")!="´ÆÐÔ"))
    {
        this_player()->set( "wishlove", times );
        return notify_fail("ÀÏÐÖ£¬²»Òª´íµãÔ§ÑìÅ¶~\n");
    } 

    if ( male->query( "age" ) < 16 || female->query( "age" ) < 14 )
    {
        this_player()->set( "wishlove", times );
        return notify_fail( "¹ýÁ½ÄêÔÙÀ´°É£¡\n" );
    }
    
    name1 = male->query("name");
    name2 = female->query("name");
    if ( random( 2 ) )
        write(  HIY"Äãò¯³ÏµØË«ÊÖºÏÊ®£¬Ä¬Ä¬µØÆíµ»µÀ£º°®Éñ\n"
            "Ñ½£¬Çë´ÍÓè" + name1 + "ºÍ" +
            name2 + "ÐÒ¸£°É£¡Ô¸ÎÒÃÇ»á\n"
            "ÓÀÔ¶ÏàÇ×Ïà°®£¬»¥Ïà·ö³Ö£¬°®»ðÓÀ²»Ï¨Ãð£¡\n" );
    if ( !random( 10 ) )            
        call_out("show_picture", 2 , name1, name2);
    return 1;
}

void remove_wish( object me )
{
    me->delete_temp( "wishlove" );
}

void show_picture(string name1, string name2)
{
    string str;
    str = HIW "Ö»Ìý¼û¶«·½ºäÂ¡Â¡µØÏìÁËÒ»Éù£¬Ò»¸öæ¯ÃÀµÄÅ®Éù\n"
        "ÏìÆð£º\n\t" HIM + name1 + 
       NOR "" BLU "ºÍ" NOR "" HIM + name2 + NOR "" BLU"½«ÔÚÎÒµÄ±Ó»¤ÏÂÓÀÔ¶\n"
        "ÐÒ¸££¡ÎÒÒÔ°®ÉñµÄÃûÒåÆðÊÄ£¡\n\n\n" NOR;
    tell_room( this_object(), str );
    call_out("show_flower", 1, name1, name2);
}

void show_flower(string name1, string name2)
{
    string str; 
    string picture = pic[random(sizeof(pic))]; 
    string color = color1[random(sizeof(color1))]; 
    picture = replace_string(picture, "$BLINK$", BLINK); 
    picture = replace_string(picture, "$NOR$", NOR+color); 
    str = "Ìì¿ÕÖÐÍ»È»ÉÁ³öÒ»µÀÑ¤ÀöµÄ»ð»¨£¬Ò»¸ö¾Þ´óµÄÍ¼°¸Öð½¥\n" 
         "ÏÔÏÖ£º\n"; 
    str += color + picture + NOR; 

    str += YEL "ËÄÏÂÀïÒþÒþ´«À´ÖÚÈËÉî³ÁµÄ×£¸£Éù£º\n"
        "     ¡°"HIM + name1 + NOR""YEL"ºÍ"NOR""HIM +
        name2 + NOR""YEL"ÓÀÔ¶ÐÒ¸£...\n"
        "                                           ÓÀÔ¶ÐÒ¸££¡£¡¡±\n\n\n";
    tell_room( this_object(), str );
    if ( !random( 4 ) )
        call_out( "show_flower", 2 ,name1, name2 );
}

