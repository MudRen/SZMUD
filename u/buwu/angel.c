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
    set_name(HIW"������ʹ"NOR, ({ "angel" }) );
    set("race", "����");
    set("age", 1);
    set("long", "һ����������ʹ����������������ο�ֱ����ҵ�����ģ�/by xrz \n");
    set("attitude", "peaceful");
    set("gender", "Ů��");
    set("age", 18 );
    set("title", HIG"��ο���˵���"NOR);
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
        "compensate" : (:AskCom:),
    ]));

    setup();
}

void init()
{
    add_action( "Compensate", "compensate" );
    add_action( "ReGift", "rebalance" );
}

string AskAll()
{
    return ""CYN"�����ѯ�����й� gift(�츳)�� compensate(����)����Ϣ��"NOR"\n";
}

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
    //return sprintf( "This is the effort to balance player's gifts�:\n\n"
    //      "Usuage as follows:\n"
    //      "rebalance n1 n2 n3 n4\n"
    //      "The total you can add is: %d", total );
    if ( total > 0 )
        return sprintf( "����ƽ������츳��ħ����������ҵ��츳������ƽ�⵽ 88 �㡣\n"
           "�������200K���Ͼ������ʹ������ܡ�\n"
           "����������·�ʽʹ��������\n"
           "rebalance n1 n2 n3 n4\n"
           "��ס�������ֻ����һ�Σ�n1+n2+n3+n4  ��������� %d һ��! \n", total );
    else
    {
        return "����츳�Ѿ������ˣ�\n";
    }
}   
           
string AskCom()
{
    return ""CYN"�����ʹ�����µ�ħ�����ָ������ֺ����ܵ�����ʧ:\n"
           " 1. compensate gift ����/����/����/�� (���첻����)\n"
           "    (�����ʲô������ָ�������������ָ�һ�������츳��)\n\n"
           " 2. compensate exp/neili/jingli \n"
           "    �� compensate skill skill_name \n"
           "    ( ��ÿ�ο���ѡ��ָ� 20k exp, �� 100 max neili �� 100 max jingli\n"
           "     ��ָ�ĳ��ܵ������ȡ������������ѡ���лָ�һ����������ָ��ĴΡ�)"NOR"\n";
           
           
}
       
void ComGift( string type, object me )
{
    switch( type )
    {
    case "����":
        me->add( "str", 1 );
        break;
    case "����":
        me->add( "int", 1 );    
        break;    
    case "����":
        me->add( "con", 1 );  
        break;
    case "��":
        me->add( "dex", 1 );
        break;
    default:
        write( "What?\n" );
        return;
    }
    me->set( "Crash/compen", 10 );
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
        write( "Hehe, ǧ�����֣�����\n" );
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
        return notify_fail( "��̫̰�������㹻�ֲ������ʧ�ˡ�\n" );
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
        return notify_fail( "��200K�����ɡ�\n ");
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
}
