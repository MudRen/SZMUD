#include <ansi.h>
 
inherit ITEM;
 
void create()
{
    set_name(RED BCYN "������" NOR, ({"biyu dan", "dan"}));
    set_weight(20);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("value", 100000);
        set( "long", HIW"����һ�ž�Ө��͸��С���ӣ���ס�͸���������к���һ���̺ۡ�\n"
                +"�ݴ�����ֻ������ź���֮�вſɲ�����\n"NOR );
        set("medicine", 1);
    }
 
    setup();
}
 
int feed_ob(object ob)
{
    int lever = 0;
    lever = ob->query_skill( "beauty", 1 );
    if ( ob->query( "gender" ) == "����" )
    {
        message_vision( "$N����һ�ű����飬�����������Բ��ϣ��������������ð������㡣\n", ob );
        ob->add( "per", -1 );
        destruct(this_object());
    return 1;
    }    
    if ( ob->query( "gender" ) != "Ů��" )
    {
        message_vision( "$N����һ�ű����飬ֻ�Ǿ��úܺóԡ�\n", ob );
        destruct(this_object());
    return 1;
    }    
    if ( ob->query( "beautydan", 0 ) )
    {
        lever = lever - 50;
        if ( lever < 1 )
            lever = 1;
        message_vision( "$N�ֳ���һ�ű����飬���ڷ�ʳ���࣬�ָֻ�����ǰ����ò��\n", ob );
        ob->set_skill( "beauty", lever );
        ob->add( "per", -1 );
        ob->delete( "beautydan" );
        destruct(this_object());
    return 1;
    }            
    lever = lever + 50;
    ob->set_skill( "beauty", lever );
    ob->add( "per", 1 );
    message_vision("$N���Ὣ�����麬�����У�ֻ��һ˿��������ı�˿���и����������������\n"
            + "��׵���ٻ������ת��Ƭ�̣��������о��鲼ȫ�������˫Ŀ�����������˿΢����\n"
            + "��о�$N����ò�������˱仯�� \n",ob );
    log_file("beauty", ob->name() + "(" + ob->query("id") 
            + ") eat a beauty dan at " + ctime(time()) + "\n");
    ob->set( "beautydan", 1 );
    destruct(this_object());
    return 1;
}
 
