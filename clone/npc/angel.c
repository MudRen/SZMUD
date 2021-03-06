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
        "chunjie" : (:AskCom:),
    ]));

    setup();
}

void init()
{
    add_action( "Compensate", "compensate" );
    //add_action( "ReGift", "rebalance" );
}

string AskAll()
{
    return "你来问我有关gift(天赋)和chunjie(春节礼物)的消息吧！:)\n";
}

string AskGift()
{
	object me = this_player();
    if ( me->query( "birthday" ) < 1013496631  && !me->query( "Crash/gift"))
        return ""CYN"你经历过这个站一天当机三次的日子吗？\n"HIR"新年娃娃"NOR"接着说道："CYN"呵呵，冬天终于过去了。你可以获得一点天赋，以纪念那两个月！\n"NOR"你可以用以下方式来获得这一点天赋奖励：\n\n compensate gift 根骨/臂力/身法/悟性) "NOR"\n";
    else
        return ""CYN"你没有和我们一起经历那段一天当机三次的日子，不能给这么厚重的礼物！"NOR"\n";
}              
string AskCom()
{
    return ""CYN"你准备好拿新年礼物了吗？\n\n\n"
           ""NOR"    命令格式：compensate exp/neili/jingli \n"
           "    或 compensate skill skill_name \n"
           "    ( 你每次可以选择恢复 20k exp, 或 100 max neili 或 100 max jingli\n"
           "     或恢复某项技能的熟练度。你可以在上述选择中恢复一项，允许连续要求四次。)"NOR"\n";
           
           
}
       
int ReGift( string type, object me )
{

    if ( me->query( "birthday" ) > 1013437959 )
    {
        return notify_fail( "你不能获得如此厚礼！\n ");
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


void AddSkill( string skillType, object me, int com )
{
    int points = 100;
    float pot;
    int lever, uLever;
    float p = 0.333333;
    if ( skillType == "qianzhu-wandu" )
    {
        write( " 千蛛万毒手这么阴毒的武功，还是自己学吧。\n" );
        return;
    }
    if ( skillType == "huagong-dafa" )
    {
        write( "化功大法？还是从别处学吧。\n" );
        return;
    }
    if ( SKILL_D(skillType)->type()=="knowledge" )
    {
        write( "呵呵, 知识类的技能，还是自己学习去吧！\n" );
        return;
    }
    uLever = me->query_skill( skillType, 1 );
    write( sprintf("skill lever %d\n", uLever) );
    if ( !uLever )
    {
        write( "你没有这项技能。\n" );
        return;
    }
    uLever++;
    //write( sprintf( "%d\n", points ) );
    pot = ( float ) uLever/10.0;
    pot = pot*pot*pot;
    pot += points;
    pot = pow( pot, p );
    //write( sprintf( "%f\n", pot ) );
    points = pot*10;
    //write( sprintf( "%d\n", points ) );
    points ++;
    me->set_skill( skillType, points );
    com++;
    write( "增加一项技能，好。\n" );
    me->set( "Crash/chunjie", com );
    return;
    // add skill, should query whether player has this skill or not
}

int Compensate( string arg )
{
    object me = this_player();
    int com;
    int com1;
    string type, giftType;
    string skill, skillType;
    string fMsg = "请使用 ask angel about gift 来询问如何使用。\n";

    com = (int) me->query( "Crash/chunjie", 0 );
    com1 = (int) me->query( "Crash/gift", 0 );
    
    if ( !arg )
        return notify_fail( fMsg );

    if ( sscanf( arg, "%s %s", type, giftType ) )
    {
        if ( gDebug )
            write( "In add gift.\n" );
        if ( type == "gift" )
        	//return notify_fail( "此项功能今天不开放。\n" );
        {
            if ( com1 <= 0 )
                ReGift( giftType, me );
            else
                write( "你已经得到一点天赋了，别太贪心了。");
        }
        else if ( type == "skill" )
        {
        if ( com >= 4 )
        	return notify_fail( "别太贪心啦，你已经得到今年春节的礼物了。\n" );
            AddSkill( giftType, me, com );
        }
        else
            write( fMsg );
        return 1;            
    }
 	if ( com >= 4 )
        return notify_fail( "别太贪心啦，你已经得到今年春节的礼物了。\n" );
        
    if ( sscanf( arg, "%s", type) )
    {
        
        if ( type == "neili" )
        {
            if ( com < 5 )
            {
                com++;
                me->add( "max_neili", 100 );
                write( "100 内力，好。\n" );
                me->set( "Crash/chunjie", com );
            }    
        }
        else if ( type == "jingli" )
        {
            if ( com < 5 )
            {
                com++;
                me->add( "max_jingli", 100 );
                me->add( "eff_jingli", 100 );
                write( "100 精力，好。\n" );
                me->set( "Crash/chunjie", com );
            }             
        }
        else if ( type == "exp" )
        {
            if ( com < 5 )
            {
                com++;
                me->add( "combat_exp", 20000 );
                write( "20000 exp。好。\n" );
                me->set( "Crash/chunjie", com );
            }    
        }
        else
            write( fMsg );
        return 1;
    }
 
}
/*
int ReGift( string arg )
{

    int str, inte, con, dex, total, uTotal, com;
    object me = this_player();
    if ( me->query( "birthday" ) > 1013437959 )
    {
        return notify_fail( "你的天赋已经很好了！\n ");
    }  
    if ( me->query( "gift/adjusted" ) )
        return notify_fail( "你已经使用过这个功能了!\n" );
    if ( !arg )
        return notify_fail( "please use ask angle about .. to know how to use it.\n" );
    inte = (int) me->query( "int" );
    str = (int) me->query( "str" );
    con = (int) me->query( "con" );
    dex = (int) me->query( "dex" );

    total = str + inte + con + dex;
    total = gMaxGift - total;
    
    //?? Need find out real varible
    if ( (string)me->query( "fupldan" ) == "yes" )
        total += 2;
    if ( me->query( "taohua_maze" ) )
        total +=1;    
    //??
    com = (int) me->query( "Crash/compen", 0 );  
    if ( com > 6 )
        total++;    
    if ( !sscanf( arg, "%d %d %d %d", str, inte, con, dex ) )
        return notify_fail( "\n" );

    if ( str<0 || inte<0 || con<0 || dex<0 )
    {
        write( "任何一项不得小于零。\n" );
        return 1;
    }
    uTotal = str + inte + con + dex;
    if ( uTotal != total )
        return notify_fail( "Total is not right.\n" );
    me->set( "gift/adjusted", 1 );
    me->add( "str", str );
    me->add( "int", inte );
    me->add( "con", con );
    me->add( "dex", dex );
    return 1;
}*/
/*int ReGift( string arg )
{

    int str, inte, con, dex, total, uTotal, com;
    object me = this_player();


    if ( !arg )
        return notify_fail( "请使用 ask angel about gift 来获得进一步信息。\n" );
    inte = (int) me->query( "int" );
    str = (int) me->query( "str" );
    con = (int) me->query( "con" );
    dex = (int) me->query( "dex" );

    total = str + inte + con + dex;
    
    //?? Need find out real varible
    if ( !sscanf( arg, "%d %d %d %d", str, inte, con, dex ) )
        return notify_fail( "\n" );

    if ( str<0 || inte<0 || con<0 || dex<0 )
    {
        write( "任何一项不得小于零。\n" );
        return 1;
    }
    uTotal = str + inte + con + dex;

    if ( uTotal != total + 1 )
        return notify_fail( "你选的总和不对，请重新输入。\n" );
    me->set( "Crash/gift", 1 );
    me->set( "str", str );
    me->set( "int", inte );
    me->set( "con", con );
    me->set( "dex", dex );
    tell_object(me,"已完成！");
    return 1;
}
*/