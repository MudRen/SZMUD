//Cracked by Roath
// liumang.c ��å

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIG"����ˮ"NOR, ({ "xiao qiushui", "qiushui", "xiao" }));
	set("gender", "����");
	set("age", 26);
	set("long", "��������˹��һ��ʦ��������ˮ���������ػ��Ű�����ɫ����ķ��䡣\n");
	set("title", "��˹��һ��ʦ");
	set("nickname", "���Ƥ");
	
	set("combat_exp", 1000);
	set("shen_type", -1);
	
	set("attitude", "heroism");
	
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);

	setup();
	carry_object("/clone/misc/cloth")->wear();
}
