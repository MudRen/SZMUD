// NPC: /d/jueqing/npc/zhang.c
// jiuer 09/2001

// Please don't move this npc from the local site.
// Please use call_out if npc disappearred.
// Zhang is a quest npc.

#include <ansi.h>  
inherit NPC;
void destroying(object, object);
string ask_key();

private string *homes_locations = ({
	"/d/jueqing/dating",
	"/d/jueqing/chufang",
	"/d/jueqing/shishi1",
	"/d/jueiqng/danfang",
});

void create()
{
	set_name("�Ŷ���", ({ "zhang ershu","zhang" }));
	set("long","һ���ҳ���ʵ��������\n");
	set("title", "�ܼ�");
	set("age", 50);
	set("gender","����");
	set("attitude","peaceful");
	
	set("str", 22);
	set("dex", 22);

	set("shen_type",0);
	set("combat_exp", 50000);
	set("no_get_from", 1);
    
	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_skill("force",60);
	set_skill("parry",60);
	set_skill("strike",60);
	set_skill("throwing",60);
	
	    //set("qi", 3000);
        set("max_qi", 3000);
	//	set("jing", 3000);
        set("max_jing", 3000);
	//	set("jingli", 3000);
     //   set("max_jingli", 3000);
	//	set("neili",3000);
	//	set("max_neili",3000);

        set_temp("apply/attack", 30);
        set_temp("apply/attack", 30);
        set_temp("apply/damage", 15);

	set("chat_chance",30);
	set("chat_msg", ({
		"�Ŷ���첽���˹�������ɫ���ŵػ��������ܡ�\n",
			(: random_move :)
	}) );
   
	set("inquiry", ([
		"all" : "�����������ʮ�������޶�Ҫ��ʲô���ʰɡ�\n",
		"��ǧ��" : "�����ҵ���ĸѽ�� �����˺ö����ˡ�\n",
		"����ֹ" : "�Ҽ�ׯ��������Ҳ����еģ�û��ء�\n",
		"��������" : "�Ҽ�С���Сû�������һ��������ġ�\n",
		"key" : "û�Ҽ����˵������Կ�ײ��ܸ��㡣\n",
		"Կ��" : "û�Ҽ����˵������Կ�ײ��ܸ��㡣\n",
		"��¸" : "�ٺ٣������ǴӺ�˵���ţ�\n",
		"��֥" : "��˵���˵�֥������ű�����\n",
		"����" : "��������һ����ׯ���������¡�\n",
		"ׯ��" : "��ˮ��ɽׯ���Ҽ�ׯ������ֹ���С�\n",
		]));
	
	set("stay_chance", 1);
	setup();
	
        carry_object("/d/jueqing/npc/obj/greenrobe")->wear();
	carry_object("/d/jueqing/obj/ciping");
}

private void go_home()
{
        if( !living(this_object()) ) return;
        message_vision("$N�첽���˹�����\n$N���ŵ��뿪�ˡ�\n", this_object());
		this_object()->move(homes_locations[random(sizeof(homes_locations))]);
		message_vision("$N�첽���˹�����\n", this_object());
}
void init()
{
        if( strsrch(file_name(environment()), "/d/jueqing/") == -1 ) {
                remove_call_out("go_home");
                call_out("go_home", 1);
                return;
		}
}
int accept_object(object me, object obj)
{
	object key;
	if ((string)obj->query("id")=="shou ling") 
	{
		message("vision",me->name()+"���Ŷ���һ�����\n",environment(me),
			({me}));
        command("bow "+me->query("id"));
        command("say " + RANK_D->query_respect(me) + 
			"��Ȼ��ׯ����������Ҿ͸���֥��Կ�ס�");
        
                key = new("/d/jueqing/npc/obj/zfkey");
        key->move(me);
        
		message_vision("$n�ݸ�$Nһ��Կ�ס�\n", me, this_object() );
        remove_call_out("destroying");
        call_out("destroying", 1, this_object(), obj);
        return 1;
	}
		return notify_fail("û�Ҽ����˵������Կ�ײ��ܸ��㡣\n");
}
void destroying(object me,object obj)
{
        destruct(obj);
        return;
}
int accept_kill(object me)
{
	command("say ���컯��֮�¾�������ɱ�ˣ�û��������\n");
	kill_ob(me);
	return 1;
}
