// �汾��Ϣ: /d/jueqing/npc/jiading.c   �Ҷ�
// by jiuer 8/21/01
// �ļ�����  NPC  

#include <ansi.h>
inherit NPC;

void create()
{
//	object bj;
	
	set_name("������", ({ "jiading","jia ding" }));
	set("long",
		"һ�����ð����Բ��С���ӣ�һ�����´�磬\n"
		"˵��ʱ��¶�н�������û��һ˿��Ц�ݡ�\n\n");
	
	set("age", 25);
	set("combat_exp", 3000);
	set("gender","����");
	set("attitude","peaceful");
	
	add_money("coin",100);
	
	set("str", 22);
	set("dex", 20);
	set("con", 19);
	set("int", 18);
	
	set_skill("blade", 30);
	set_skill("unarmed", 30);
	set_skill("parry", 30);
	set_skill("force", 30);
	set_skill("sword", 30);
	set_skill("dodge", 30);
      
	set("jingli",200);
	set("neili",200);
	set("jing",200);
	set("qi",200);
     setup();
        carry_object("/d/jueqing/npc/obj/greenrobe")->wear();
	carry_object("/d/city/obj/changjian")->wield();
	carry_object("/d/dali/npc/obj/dagger");
}
