/***************************************************************************
[19] �ҵĵ�һ��npc����                        ��˸(spark)(Wed May 29)
----------------------------------------------------------------------
l laoren
����һ���뷢�԰׵����ˡ����ż��ӣ���Ŀ���顣������ʯ�����������š�

ask laoren about all
����̾��һ������������˵����֪�������ʲô�أ���here������������ݾޱ䡢������ɣ��ʯ�������ˣ�

ask laoren about here
�������˴����йء�here������Ϣ��
����˵�������������ݵ���ʷ����ݡ�

ask laoren about ��������
����΢΢һЦ��˵������ν���ƣ��紵�ƶ�����ֹ��ɢ������Щ�ɡ�

ask laoren about ���ݾޱ�
����ͣ��һͣ��˵���������ǵ�Ŭ����Ϣ��������ı��Ī�⣬˭��˵�ú��أ�

ask laoren about ������ɣ
�����ƺ�����Զ����������˵��һ�뽭�����´ߡ�ȥ����Щ�������˵ĸ��ܰɡ�

ask laoren about ʯ��
���˿���ʯ������Ĭ��һ�����˵���������������İ���

ask laoren about ����
���˻���תͷ���˿��㣬¶��һ˿΢Ц����ֻ�Ǹ����ͣ����ſ��žͲ�ɣǧ���ˡ�



ллlisser 
    :)
*******************************************************************************/
//create by Karlopex@sz
//�͸�spark����С���
#include <ansi.h>
inherit NPC;
#include "/newjob/doctor/list.h"
string ask_maple();
string ask_sword();
void create()
{
        set_name("��������", ({ "wuming laoren", "laoren", "oldman"}));
        set("long", "����һ���뷢�԰׵����ˡ����ż��ӣ���Ŀ���顣������ʯ�����������š�\n");
        set("gender", "����");
        set("age", 1000);
        set("attitude", "friendly");
        set("shen_type", 1);
        set("str", 30);
        set("int", 100);
        set("con", 50);
        set("dex", 50);
        set("kar", 30);
        set("per", 30);

        set("max_qi", 10000);
        set("max_jing", 6000);
        set("neili", 8000);
        set("max_neili", 8000);
        set("jiali", 100);
        set("score", 5000);

        setup();
        carry_object("/d/city/obj/cloth")->wear();
}
void init()
{
        add_action("do_ask","ask");
}
int do_ask(string arg)
{
        object me = this_player(), ob;
        string dest, topic;
        if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
                return notify_fail("��Ҫ��˭ʲô�£�\n");

        if( !objectp(ob = present(dest, environment(me))) )
                return notify_fail("����û������ˡ�\n");
                
        if( ob == this_object())
        { 
                if ( topic == "all" ){
	                message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);
                        command("sigh");
                        message_vision(WHT"$N����˵������֪�������ʲô�أ���here������������ݾޱ䡢������ɣ��ʯ�������ˣ�\n"NOR, this_object());
                }else if ( topic == "here" ){
	                message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);
                        command("hehe");
                        message_vision(WHT"$N˵�������������ݵ���ʷ����ݡ�\n"NOR, this_object());
                }else if ( topic == "��������" ){
	                message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);
                        command("smile");
                        message_vision(WHT"$N˵������ν���ƣ��紵�ƶ�����ֹ��ɢ������Щ�ɡ�\n"NOR, this_object());
                }else if ( topic == "���ݾޱ�"){                                        
	                message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);
	                 message_vision(WHT"$Nͣ��һͣ��˵���������ǵ�Ŭ����Ϣ��������ı��Ī�⣬˭��˵�ú��أ�\n"NOR, this_object()); 
                }else if ( topic == "������ɣ" ){                       
	                message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);
                        command("idle2");
                        message_vision(WHT"$N������˵��һ�뽭�����´ߡ�ȥ����Щ�������˵ĸ��ܰɡ�\n"NOR, this_object());
                }else if ( topic == "ʯ��" ){                   
	                message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);
                        message_vision(WHT"$N����ʯ������Ĭ��һ�����˵���������������İ���\n"NOR, this_object());
                }else if ( topic == "����" ){                   
	                message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);
                        message_vision(WHT"$N����תͷ���˿��㣬¶��һ˿΢Ц����ֻ�Ǹ����ͣ����ſ��žͲ�ɣǧ���ˡ�\n"NOR, this_object());
                }else return "/cmds/std/ask.c"->main(me, arg);
                return 1;
        }
        return "/cmds/std/ask.c"->main(me, arg);
}
