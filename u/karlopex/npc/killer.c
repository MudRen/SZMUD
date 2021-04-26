//Cracked by Roath
// npc: /d/city/npc/ftb_killer.c
// Chu 2/10/99

#include <ansi.h>
inherit NPC;
#include "name.h"

string ask_cike();
string ask_move();

void create()
{
	if (random(10) == 5){
	        set_random_name("Ů��");
	        set("gender", "Ů��" );
	}else{
	        set_random_name("");
	        set("gender", "����" );
	}
        set("title", "���ĵ�����ΣУ�" );
        set("long", "���Ǵ̿ͣ������֪��ʲô�Ļ���ask me about all\n" );
        set("age", 32);
        set("str", 23);
        set("dex", 30);
        set("con", 23);
        set("int", 23);
        set("shen_type", -1);

        set("max_qi", 300);
        set("max_jing", 100);
        set("neili", 200);
        set("max_neili", 200);

        set("no_refresh", 1);

        setup();
/*        set("inquiry", ([
		"all" : "�ҿ��Ը������й�\n��"+this_player()->name(1)+"��"+this_player()->query("id")+"��kill me ?��ɱ�ң����̿͡�cike�������顣\n",
		this_player()->name(1) : "���֪��"+this_player()->name(1)+"��������\n",
		this_player()->query("id") : "���֪��"+this_player()->name(1)+"��������\n",
		"kill me ?" : (: ask_move :),
		"ɱ�ң�" : (: ask_move :),
		"�̿�" : (: ask_cike :),
		"cike" : (: ask_cike :),
        ]));*/
        carry_object("/clone/armor/beixin")->wear();
        remove_call_out("self_destruct");
        call_out("self_destruct", 1200);

}
void init()
{
	add_action("do_ask","ask");
}
int do_ask(string arg)
{
	object me = this_player();
	string dest, topic;
	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�£�\n");
	else{ 
		delete("inquiry");
	        set("inquiry", ([
			"all" : "�ҿ��Ը������й�\n��"+me->name(1)+"��"+this_player()->query("id")+"��kill me ?��ɱ�ң����̿͡�cike�������顣\n",
			me->name(1) : "���֪��"+me->name(1)+"��������\n",
			me->query("id") : "���֪��"+me->name(1)+"��������\n",
			"kill me ?" : (: ask_move :),
			"ɱ�ң�" : (: ask_move :),
			"�̿�" : (: ask_cike :),
			"cike" : (: ask_cike :),
	        ]));
		return "/cmds/std/ask.c"->main(me, arg);
        }
}
void self_destruct() {
    object me = this_object();
    message("vision", name(1)+"˵������ֻ�й��֪����Ҫ��ɱ��Ŀ���������\n˵�꼱��ææ���뿪�ˡ�\n", environment(me), me);
    destruct(me);
}

string ask_cike() 
{
	if (random(100) < 10)
		return "����ô�����㵹���Ǹ�ɱ���أ�";
	else return "����Ц������̫ƽ�úܣ������д̿ͣ�";
}

string ask_move()
{
	object player, room;
	mapping exits;
	string  *dirs;
	
	player = this_player();
	if (random(100) < 10)  {
		room = environment(this_object());
		exits = room->query("exits");
		dirs = keys(exits);
		command("!!! ");
		command("go "+dirs[random(sizeof(dirs))]);
		return this_player()->name(1)+"��������𡣡�����ɱ�ң�";
	}else return "�����ܣ����������"+this_player()->name(1)+"�ɣ�";
}
