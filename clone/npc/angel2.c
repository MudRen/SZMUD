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
    return "�����ѯ�����йز���(ask angel about gift)����Ϣ��\n";
}

string AskGift()
{
        object me = this_player();
    if ( me->query( "birthday" ) < 1024125352   && !me->query( "Crash/gift2"))
        return ""CYN"�㾭����ǰ����ĵ�����\n"HIR"��������"NOR"����˵����"CYN"�Ǻǣ��������ں��ˡ�����Ի��һ���츳���Բ��������ʧ��\n"NOR"����������·�ʽ�������һ���츳������\n\n compensate gift ����/����/��/����), ���� compensate gift 0/0/1/0  "NOR"\n";
    else
        return ""CYN"��û�к�����һ�����Ƕ�һ�쵱�����ε����ӣ����ܸ���ô���ص����"NOR"\n";
}              
       
int ReGift( string type, object me )
{

    if ( me->query( "birthday" ) > 1013437959 )
    {
        return notify_fail( "���ǵ�����ų�����������ܻ��һ���츳�Ĳ�����\n ");
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
