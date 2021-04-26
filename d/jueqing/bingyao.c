// Filename:   /d/jueqinggu/bingyao.c ��Ҥ
// Program:    Jiuer
// Date:       Aug 2001

#include <ansi.h>
#include <room.h>
inherit ROOM;

int idle();
private int idle_result(object pl);

void create()
{
        set("short",HIW"��Ҥ"NOR);
        
        set("long",@LONG
������һ����̶��бͨ���ϵı��ѡ����ۿ�ȥ��������ɭɭ������
�����ƺ���������������Ҥ����̹ǣ��㲻���ڱ�Ҥ����˸���ս��
LONG);
        set("exits",([
                "eastup" : __DIR__"garden",
                ]));
        set("outdoors","jueqing");
        set("cost",1);
        setup();
}
void init()
{
        add_action("do_dive","dive");
        remove_call_out("idle");
        call_out("idle",4 + random(3) );
}

int do_dive(string arg)
{
        object me = this_player();

        if(!arg||arg=="")
                return 0;
        if(arg =="tan")
        {
                message_vision("$N�������˼�������һ������Ǳ��Ҥ���̶ˮ��ȥ��\n\n",me);
                me->start_busy(3);
                me->move(__DIR__"bishuitan");
                message_vision("$N����̶ˮ�ĸ�����������ˮ�档\n\n\n",me);
                return 1;
        }
}

int idle()
{
        object *inv = all_inventory(find_object("d/jueqing/bingyao"));
        object ob, me= this_player();
        int i;

        if( !this_player() || !environment(this_player()) )  return 1;
        if( base_name(environment(this_player())) != "/d/jueqing/bingyao") return 1;

        message_vision("\n��������ֳ���������Ķ��룬�㲻�����˸������\n", this_player() );

        for ( i=0 ; i < sizeof(inv); i++)
        {
                if ( (string)inv[i]->query("race") == "����" )
                {
                        idle_result(inv[i]);
                }
        }

        remove_call_out("idle");
        call_out( "idle",4 + random(3) );
        return 1;
}

private int idle_result(object pl)
{
        int gain = 1;
        
        if( pl->query("family/family_name") == "��Ĺ��"
                && pl->query_skill("suxin-jue",1) >= 100 
                && !pl->is_busy()){
                message_vision(HIW"\n$N�Ա������ľ������¼ţ�\n"NOR, pl );
                
				gain += pl->query_skill("suxin-jue",1)/5;
                gain += pl->query_skill("lovingness",1)/10;
                
				pl->improve_skill("suxin-jue", gain);
                pl->start_busy(gain/10);
        }
        else{
                message_vision("\n$N���˸���������Ƶذ�̾һ����\n", pl );
        }

        return 1;
}
