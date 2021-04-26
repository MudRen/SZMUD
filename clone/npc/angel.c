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
    set_name(HIR"��������"NOR, ({ "angel" }) );
    set("race", "����");
    set("age", 1);
    set("long", "һ��Ư���ɰ���С���ޣ����ź�ɫ����װ�����Ǹ����ݵ���Ҵ�����������ģ�\n");
    set("attitude", "peaceful");
    set("gender", "Ů��");
    set("age", 18 );
    set("title", HIW"��������"NOR);
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
    return "���������й�gift(�츳)��chunjie(��������)����Ϣ�ɣ�:)\n";
}

string AskGift()
{
	object me = this_player();
    if ( me->query( "birthday" ) < 1013496631  && !me->query( "Crash/gift"))
        return ""CYN"�㾭�������վһ�쵱�����ε�������\n"HIR"��������"NOR"����˵����"CYN"�Ǻǣ��������ڹ�ȥ�ˡ�����Ի��һ���츳���Լ����������£�\n"NOR"����������·�ʽ�������һ���츳������\n\n compensate gift ����/����/��/����) "NOR"\n";
    else
        return ""CYN"��û�к�����һ�����Ƕ�һ�쵱�����ε����ӣ����ܸ���ô���ص����"NOR"\n";
}              
string AskCom()
{
    return ""CYN"��׼������������������\n\n\n"
           ""NOR"    �����ʽ��compensate exp/neili/jingli \n"
           "    �� compensate skill skill_name \n"
           "    ( ��ÿ�ο���ѡ��ָ� 20k exp, �� 100 max neili �� 100 max jingli\n"
           "     ��ָ�ĳ��ܵ������ȡ������������ѡ���лָ�һ���������Ҫ���ĴΡ�)"NOR"\n";
           
           
}
       
int ReGift( string type, object me )
{

    if ( me->query( "birthday" ) > 1013437959 )
    {
        return notify_fail( "�㲻�ܻ����˺���\n ");
    }  
    if ( me->query( "Crash/gift" ) )
        return notify_fail( "���Ѿ��ù�һ�������ĺ�����!\n" );
        
    switch( type )
    {
    case "����":
        me->add( "str", 1 );
        write( "����һ������������á�\n" );
        break;
    case "����":
        me->add( "int", 1 );    
        write( "����һ���������ԣ��á�\n" );
        break;    
    case "����":
        me->add( "con", 1 );  
        write( "����һ��������ǣ��á�\n" );
        break;
    case "��":
        me->add( "dex", 1 );
        write( "����һ�����������á�\n" );
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
        write( " ǧ��������ô�������书�������Լ�ѧ�ɡ�\n" );
        return;
    }
    if ( skillType == "huagong-dafa" )
    {
        write( "�����󷨣����Ǵӱ�ѧ�ɡ�\n" );
        return;
    }
    if ( SKILL_D(skillType)->type()=="knowledge" )
    {
        write( "�Ǻ�, ֪ʶ��ļ��ܣ������Լ�ѧϰȥ�ɣ�\n" );
        return;
    }
    uLever = me->query_skill( skillType, 1 );
    write( sprintf("skill lever %d\n", uLever) );
    if ( !uLever )
    {
        write( "��û������ܡ�\n" );
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
    write( "����һ��ܣ��á�\n" );
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
    string fMsg = "��ʹ�� ask angel about gift ��ѯ�����ʹ�á�\n";

    com = (int) me->query( "Crash/chunjie", 0 );
    com1 = (int) me->query( "Crash/gift", 0 );
    
    if ( !arg )
        return notify_fail( fMsg );

    if ( sscanf( arg, "%s %s", type, giftType ) )
    {
        if ( gDebug )
            write( "In add gift.\n" );
        if ( type == "gift" )
        	//return notify_fail( "����ܽ��첻���š�\n" );
        {
            if ( com1 <= 0 )
                ReGift( giftType, me );
            else
                write( "���Ѿ��õ�һ���츳�ˣ���̫̰���ˡ�");
        }
        else if ( type == "skill" )
        {
        if ( com >= 4 )
        	return notify_fail( "��̫̰���������Ѿ��õ����괺�ڵ������ˡ�\n" );
            AddSkill( giftType, me, com );
        }
        else
            write( fMsg );
        return 1;            
    }
 	if ( com >= 4 )
        return notify_fail( "��̫̰���������Ѿ��õ����괺�ڵ������ˡ�\n" );
        
    if ( sscanf( arg, "%s", type) )
    {
        
        if ( type == "neili" )
        {
            if ( com < 5 )
            {
                com++;
                me->add( "max_neili", 100 );
                write( "100 �������á�\n" );
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
                write( "100 �������á�\n" );
                me->set( "Crash/chunjie", com );
            }             
        }
        else if ( type == "exp" )
        {
            if ( com < 5 )
            {
                com++;
                me->add( "combat_exp", 20000 );
                write( "20000 exp���á�\n" );
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
        return notify_fail( "����츳�Ѿ��ܺ��ˣ�\n ");
    }  
    if ( me->query( "gift/adjusted" ) )
        return notify_fail( "���Ѿ�ʹ�ù����������!\n" );
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
        write( "�κ�һ���С���㡣\n" );
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
        return notify_fail( "��ʹ�� ask angel about gift ����ý�һ����Ϣ��\n" );
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
        write( "�κ�һ���С���㡣\n" );
        return 1;
    }
    uTotal = str + inte + con + dex;

    if ( uTotal != total + 1 )
        return notify_fail( "��ѡ���ܺͲ��ԣ����������롣\n" );
    me->set( "Crash/gift", 1 );
    me->set( "str", str );
    me->set( "int", inte );
    me->set( "con", con );
    me->set( "dex", dex );
    tell_object(me,"����ɣ�");
    return 1;
}
*/