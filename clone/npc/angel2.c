#include <ansi.h>
inherit NPC;

int gMaxGift = 88;
int gPliAjust = 2;

int gDebug = 0;

string AskAll();
string AskGift();
string AskCom();

void create()
{
    set_name(HIR"新年娃娃"NOR, ({ "angel" }) );
    set("race", "人类");
    set("age", 1);
    set("long", "一个漂亮可爱的小娃娃，穿着红色的唐装，他是给神州的玩家带来春节礼物的！\n");
    set("attitude", "peaceful");
    set("gender", "女性");
    set("age", 18 );
    set("title", HIW"恭贺新禧"NOR);
    set( "eff_qi", 100000 );
    set( "eff_jing", 100000 );
    set("max_qi", 100000);
    set("max_jing", 100000);
    set("max_jingli", 100000);
    set( "eff_jingli", 100000 );
    set( "eff_jing", 100000 );
    set( "neili", 100000 );
    set( "max_neili", 100000 );
    set( "qi", 100000 );
    set( "jingli", 100000 );
    set( "jing", 100000 );
    set( "neili", 100000 );

    set("str", 100);
    set("con", 100);
    set("dex", 100);
    set("int", 100);

    set("combat_exp", 20000000);

    set_temp("apply/attack", 1000);
    set_temp("apply/damage", 1000);
    set_temp("apply/armor", 1000);
    set("inquiry", ([
        "all" : (:AskAll:),
        "gift" : (:AskGift:),
      //  "chunjie" : (:AskCom:),
    ]));

    setup();
}

void init()
{
    //add_action( "Compensate", "compensate" );
    add_action( "ReGift", "gift" );
}

string AskAll()
{
    return "你可以询问我有关补偿(ask angel about gift)的消息。\n";
}

string AskGift()
{
        object me = this_player();
    if ( me->query( "birthday" ) < 1024125352   && !me->query( "Crash/gift2"))
        return ""CYN"你经历过前两天的当机吗？\n"HIR"新年娃娃"NOR"接着说道："CYN"呵呵，现在终于好了。你可以获得一点天赋，以补偿你的损失！\n"NOR"你可以用以下方式来获得这一点天赋奖励：\n\n compensate gift 根骨/臂力/身法/悟性), 比如 compensate gift 0/0/1/0  "NOR"\n";
    else
        return ""CYN"你没有和我们一起经历那段一天当机三次的日子，不能给这么厚重的礼物！"NOR"\n";
}              
       
int ReGift( string type, object me )
{

    if ( me->query( "birthday" ) > 1013437959 )
    {
        return notify_fail( "你是当机后才出生的人物，不能获得一点天赋的补偿。\n ");
    }  
    if ( me->query( "Crash/gift" ) )
        return notify_fail( "你已经得过一份这样的厚礼了!\n" );
        
    switch( type )
    {
    case "臂力":
        me->add( "str", 1 );
        write( "增加一点先天臂力，好。\n" );
        break;
    case "悟性":
        me->add( "int", 1 );    
        write( "增加一点先天悟性，好。\n" );
        break;    
    case "根骨":
        me->add( "con", 1 );  
        write( "增加一点先天根骨，好。\n" );
        break;
    case "身法":
        me->add( "dex", 1 );
        write( "增加一点先天身法，好。\n" );
        break;
    default:
        write( "What?\n" );
        return;
    }
    me->set( "Crash/gift", 1 );
    return;           
}       
