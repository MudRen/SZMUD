
// NPC /d/wulin/npc/shizhe.c ����
//Piao 2001/10/17
#include <ansi.h>

inherit NPC;
void create()
{
	set_name("����", ({ "shi zhe"}) );
	set("gender", "����");
	set("age", 15);
	set("long",
		"��λ������¥�����ߡ�\n");
        setup();
}
int accept_object(object me, object obj)
{
      if(obj->name() == "���") {
                command("bow "+me->query("id"));
                message_vision(CYN"����˵����"+RANK_D->query_respect(me)+"ԭ�����������˵�����, ����¥�����ɹ��ɡ�\n"NOR,me);
                me->set_temp("guibinshi",1);
                call_out("destroy_it",1,obj);
                return 1;
	}
       	return 0;
}
void destroy_it(object obj)
{
        destruct(obj);
}

