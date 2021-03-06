#include <ansi.h>
inherit NPC;

int gMaxGift = 88;
int gPliAjust = 2;

int gDebug = 0;

string AskAll();
string AskGift();
string AskCom();
int Compensate();
void create()
{
    set_name(HIW"复活天使"NOR, ({ "angel" }) );
    set("race", "人类");
    set("age", 1);
    set("long", "一个美丽的天使，是神仙们派来抚慰灾变后玩家的心灵的！/by xrz \n");
    set("attitude", "peaceful");
    set("gender", "女性");
    set("age", 18 );
    set("title", HIG"抚慰受伤的心"NOR);
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
//        "gift" : (:AskGift:),
        "compensate" : (:Compensate:),
    ]));

    setup();
}
/*
void init()
{
    add_action( "Compensate", "compensate" );
    add_action( "ReGift", "rebalance" );
}
*/
string AskAll()
{
//    return ""CYN"你可以询问我有关 gift(天赋)和 compensate(补偿)的消息。"NOR"\n";
    return ""CYN"你可以询问我有关compensate(补偿)的消息。"NOR"\n";
}
/*
string AskGift()
{
    int str, inte, con, dex, total, com;
    object me = this_player();
    inte = (int) me->query( "int" );
    str = (int) me->query( "str" );
    con = (int) me->query( "con" );
    dex = (int) me->query( "dex" );
    total = str + inte + con + dex;
    total = gMaxGift - total;
    //??need find out real varible
    if ( (string)me->query( "fupldan" ) == "yes" )
        total += 2;
    if ( me->query( "taohua_maze" ) )
        total +=1;
    //??
    com = (int) me->query( "Crash/compen", 0 );  
    if ( com > 6 )
        total++;        
    //return sprintf( "This is the effort to balance player's gifts猓:\n\n"
    //      "Usuage as follows:\n"
    //      "rebalance n1 n2 n3 n4\n"
    //      "The total you can add is: %d", total );
    if ( total > 0 )
        return sprintf( "这是平衡玩家天赋的魔法。所有玩家的天赋都可以平衡到 88 点。\n"
           "你必需有200K以上经验才能使用这项功能。\n"
           "你可以用以下方式使用这个命令：\n"
           "rebalance n1 n2 n3 n4\n"
           "记住这个命令只能用一次，n1+n2+n3+n4  必需和总数 %d 一样! \n", total );
    else
    {
        return "你的天赋已经够好了！\n";
    }
}   
           
string AskCom()
{
    return ""CYN"你可以使用以下的魔法来恢复你在灾害中受到的损失:\n"
           " 1. compensate gift 臂力/悟性/根骨/身法 (今天不开放)\n"
           "    (如果你什么都不想恢复，可以在这里恢复一点永久天赋。)\n\n"
           " 2. compensate exp/neili/jingli \n"
           "    或 compensate skill skill_name \n"
           "    ( 你每次可以选择恢复 20k exp, 或 100 max neili 或 100 max jingli\n"
           "     或恢复某项技能的熟练度。你可以在上述选择中恢复一项，允许连续恢复四次。)"NOR"\n";
           
           
}
       
void ComGift( string type, object me )
{
    switch( type )
    {
    case "臂力":
        me->add( "str", 1 );
        break;
    case "悟性":
        me->add( "int", 1 );    
        break;    
    case "根骨":
        me->add( "con", 1 );  
        break;
    case "身法":
        me->add( "dex", 1 );
        break;
    default:
        write( "What?\n" );
        return;
    }
    me->set( "Crash/compen", 10 );
    return;           
}       
*/
int Compensate()
{
    object me = this_player();
        if ( me->query("AddGift/angel/Down-Jul") )
        	return notify_fail( "已经补偿你了，不要太贪心了。\n" );
    write("此次当机时间较长，巫师公会决定补偿玩家一点先天天赋(臂力、悟性、根骨、身法)。\n");
    write("你要补哪一项天赋，请使用用buchang <天赋名称>命令。\n");
    add_action("do_buchang","buchang");
    return 1;
}
int do_buchang(string arg)
{
	object me = this_player();
	if (!arg || arg == "")
        	return notify_fail( "你要补偿什么天赋？\n" );
       if ( me->query("AddGift/angel/Down-Jul") )
        	return notify_fail( "已经补偿你了，不要太贪心了。\n" );
	switch( arg )
	{
		case "臂力":
			me->add( "str", 1 );
			break;
		case "悟性":
			me->add( "int", 1 );    
			break;    
		case "根骨":
			me->add( "con", 1 );  
			break;
		case "身法":
			me->add( "dex", 1 );
			break;
		default:
			write( "你要补偿什么天赋？\n" );
			return 1;
	}        
	write( "你的先天"+arg+"得到了补偿。\n" );
        me->set("AddGift/angel/Down-Jul", 1);
	log_file("static/AddGift", sprintf("[%s]   %s   %s(%s)因为当机补偿了 一点%s。\n", 
		ctime(time())[0..15], me->query("family/family_name"), me->name(), geteuid(me),arg)); 
    	remove_action("do_buchang","buchang");
	return 1;
}

	
/*
void AddSkill( string skillType, object me, int com )
{
    int points = 100;
    float pot;
    int lever, uLever;
    float p = 0.333333;
    if ( skillType == "qianzhu-wandu" )
    {
        write( "Hehe, 千蛛万毒手？？？\n" );
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
    me->set( "Crash/compen", com );
    return;
    // add skill, should query whether player has this skill or not
}

int Compensate( string arg )
{
    object me = this_player();
    int com;
    string type, giftType;
    string skill, skillType;
    string fMsg = "USE ask angel about compensate to know how to use.\n";

    com = (int) me->query( "Crash/compen", 0 );
    if ( com >= 4 )
        return notify_fail( "别太贪心啦。足够弥补你的损失了。\n" );
    if ( !arg )
        return notify_fail( fMsg );
    if ( sscanf( arg, "%s %s", type, giftType ) )
    {
        if ( gDebug )
            write( "In add gift.\n" );
        if ( type == "gift" )
        {
            if ( com <= 0 )
                ComGift( giftType, me );
            else
                write( fMsg );
        }
        else if ( type == "skill" )
        {
            AddSkill( giftType, me, com );
        }
        else
            write( fMsg );
        return 1;            
    }
 
    if ( sscanf( arg, "%s", type) )
    {
        
        if ( type == "neili" )
        {
            if ( com < 5 )
            {
                com++;
                me->add( "max_neili", 100 );
                me->set( "Crash/compen", com );
            }    
        }
        else if ( type == "jingli" )
        {
            if ( com < 5 )
            {
                com++;
                me->add( "max_jingli", 100 );
                me->add( "eff_jingli", 100 );
                me->set( "Crash/compen", com );
            }             
        }
        else if ( type == "exp" )
        {
            if ( com < 5 )
            {
                com++;
                me->add( "combat_exp", 20000 );
                me->set( "Crash/compen", com );
            }    
        }
        else
            write( fMsg );
        return 1;
    }
 
}

int ReGift( string arg )
{

    int str, inte, con, dex, total, uTotal, com;
    object me = this_player();
    if ( me->query( "combat_exp" ) < 200000 )
    {
        return notify_fail( "拿200K再来吧。\n ");
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
}
*/
