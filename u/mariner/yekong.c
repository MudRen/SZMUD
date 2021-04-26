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
           +     $BLINK$��$NOR$           .   .      +
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

    �ģ� �٣ϣ� �ƣţţ� �ԣȣ� �̣ϣ֣� �ԣϣΣɣǣȣԣ�
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
        set("short", HIC"ҹ  ��"NOR);
        set("long", @LONG

[1;34m    .   . ��  *   ��   .    ��         .    *       ��     . 
       .      .    [1;36m[5m��[2;37;0m[1;34m     .    .  [1;36m[5m��[2;37;0m[1;34m.    [1;36m[5m��[2;37;0m[1;34m        .    
 .   .  .   [1;36m[5m��[2;37;0m[1;34m       ��   .     . .    .        .    [1;36m[5m��[2;37;0m[1;34m  
    .           ��          ��               ��            .[2;37;0m




[1;34m        ����[1;36m[5m����[2;37;0m[1;34m�����Ը ��[1;35m��[1;34m֪��[33m��[1;31m[5m��[2;37;0m[1;35m��[2;37;0m

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
        return notify_fail( "�𼱣���������\n" );
    this_player()->set_temp( "wishlove", 1 );
    call_out( "remove_wish", 2, me );
    if( !arg || sscanf(arg, "love %s", id2) != 1 )
    {
        this_player()->set( "wishlove", times );
        return notify_fail("ָ���ʽ��wish love id\n");
    }  
        
    if ( male->query("gender") != "����" )
    {
        female = this_player();
        male = present( id2, environment( me ));
    }
    else
        female = present( id2, environment( me ));
        
    if( !male || !female || !userp( male ) || !userp( female) )
    {
        this_player()->set( "wishlove", times );
        return notify_fail("����û�������Ŷ~~\n");
    }
    
    if ( ! living( male ) || ! living (female) )
        return notify_fail("������㣬�ǲ��ǻ�ġ�\n");
    if(( male->query("gender") != "����" &&  male->query("gender") != "����")
        ||(female->query("gender") != "Ů��" &&female->query("gender")!="����"))
    {
        this_player()->set( "wishlove", times );
        return notify_fail("���֣���Ҫ���ԧ��Ŷ~\n");
    } 

    if ( male->query( "age" ) < 16 || female->query( "age" ) < 14 )
    {
        this_player()->set( "wishlove", times );
        return notify_fail( "�����������ɣ�\n" );
    }
    
    name1 = male->query("name");
    name2 = female->query("name");
    if ( random( 2 ) )
        write(  HIY"���ϵ�˫�ֺ�ʮ��ĬĬ������������\n"
            "ѽ�������" + name1 + "��" +
            name2 + "�Ҹ��ɣ�Ը���ǻ�\n"
            "��Զ�����మ��������֣���������Ϩ��\n" );
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
    str = HIW "ֻ����������¡¡������һ����һ�������Ů��\n"
        "����\n\t" HIM + name1 + 
       NOR "" BLU "��" NOR "" HIM + name2 + NOR "" BLU"�����ҵıӻ�����Զ\n"
        "�Ҹ������԰�����������ģ�\n\n\n" NOR;
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
    str = "�����ͻȻ����һ��Ѥ���Ļ𻨣�һ���޴��ͼ����\n" 
         "���֣�\n"; 
    str += color + picture + NOR; 

    str += YEL "�����������������������ף������\n"
        "     ��"HIM + name1 + NOR""YEL"��"NOR""HIM +
        name2 + NOR""YEL"��Զ�Ҹ�...\n"
        "                                           ��Զ�Ҹ�������\n\n\n";
    tell_room( this_object(), str );
    if ( !random( 4 ) )
        call_out( "show_flower", 2 ,name1, name2 );
}

