//Cracked by Roath
// puren.c ���͵�����
// Long, 6/13/97

#include <ansi.h>

inherit NPC;

int ask_leave();
void greeting(object);

void create()
{
	set_name("����", ({ "xian ren", "xian"}));
	set("long", "���ǵ���һ�����ֺ��е��ˡ�\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("race", "����");	
	set("max_qi", 200);
	set("eff_qi", 200);
	set("qi", 200);
	set("max_jing", 200);
	set("eff_jing", 200);
	set("jing", 200);
	set("max_neili", 200);
	set("eff_neili", 200);
	set("neili", 200);
	set("max_jingli", 200);
	set("eff_jingli", 200);
	set("jingli", 200);
	set("combat_exp", 1000);
	set("score", 1000);

	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_skill("cuff", 20);
	set_skill("sword", 20);
	
	set("inquiry", ([
			"��ԭ"   : 	(: ask_leave :),
			"����"   : 	"������������ɽ\n",
			
		]));
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
{	if (me->query_temp(this_object()->query("id")) == 0 )
	{	command("pat " + me->query("id"));
		command("say 
         ��λ" + RANK_D->query_respect(me) + 
	          "�����͵���������ҿ�������˶���ʮ���ˡ���
   �������֮����Ժͱ������ģ���������������������顣����
   ��ɢ��Щҥ�ԣ�������򣩡����ĺ�ɢ��ҥ��ʱ������һЩ�Ѿ�
   ���˵Ķ�������������� chat* hi�� �ã���������Բ����
   Щ���Ѿ����˵Ķ���������㻰̫��������ͻᱻ��ͶƱ�رս�̸
   Ƶ����(vote chblk xxx)Ƶ�������˺�ֻ�еȱ���ͶƱ�򿪡�(vote
   unchblk xxx)��������������������������������������Ը���
   �������죩��(��)�����˸�����ʲ���£�������ã���������
   ���ش���(��)���㻹���Ը�ĳһλ������ͬһ������˽����Ļ�
   ����������򣩡������ϲ����˳������书֮�У�Ȼ���Ҿ���
   �������Ľ��Ѹ���Ȥ�������Ϊ֮�ɡ�");
		command("yawn");
		me->set_temp(this_object()->query("id"), 1);
	}

}
int ask_leave()
{	command("shake ");
	command("say û�е���ͬ�⣬��ɲ���˽���뵺��");
	return 1;
}
