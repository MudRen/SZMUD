//Cracked by Roath
// xiaotong.c Сͯ
// Long, 6/13/97

#include <ansi.h>
inherit NPC;

void greeting(object);


void create()
{
	set_name("С��", ({ "xiao tong", "tong"}));
	set("long", "���Ǹ����䲻���С�к������Ѻܽ�׳�ˡ�\n");
	set("gender", "����");
	set("age", 14);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("race", "����");	
	set("max_qi", 150);
	set("eff_qi", 150);
	set("qi", 150);
	set("max_jing", 150);
	set("eff_jing", 150);
	set("jing", 150);
	set("max_neili", 150);
	set("eff_neili", 150);
	set("neili", 150);
	set("max_jingli", 150);
	set("eff_jingli", 150);
	set("jingli", 150);
	set("combat_exp", 1000);
	set("score", 1000);

	set_skill("force", 5);
	set_skill("dodge", 5);
	set_skill("parry", 5);
	set_skill("cuff", 5);
	set_skill("sword", 5);
	
//	set("inquiry", ([
//			""   : 	"\n",
//		]));
	setup();
}

void init()
{
        object me = this_player();        

        ::init();

        if( interactive(me) )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

void greeting(object me)
{	command("bow " + me->query("id"));
	command("say �����ҪЩ�ԵĻ�ȵ�ֻҪ����һ��"+HBRED+HIW"(serve)"NOR+"��");
}

int accept_object(object me, object obj)
{
        call_out("accept_obj", 1, me, obj);
        return 1;
}

int accept_obj(object me, object obj)
{
        object ke;
        if( obj->query("name")=="Ҭ��") 
	  {
	     command("xixi "+ me->query("id"));
	     message_vision("$N�ӹ�Ҭ�ӣ��ͳ�һ��С�������������˸�����Ц���еذ�Ҭ�ӿǻ������㡣\n", this_object());
	     ke = new("/d/xiakedao/obj/yezike");
	     ke->move(this_player());
	     return 1;
	  }
	else 
	  {
             command("? "+ me->query("id"));
	     return 0;
	  }
}
 
