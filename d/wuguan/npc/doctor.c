/*-------------------------------------------------------------
** �ļ���: doctor.c
** Copyright (c) 2000-2001
** ������: ��ݹ�����
** ��  ��: 2001/08/13
** ��  ��: ��ҽ
**-----------------------------------------------------------*/
#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
	set_name("��ҽ", ({ "shen yi", "yi", "doctor" }));
	set("long", "���ǽ����д��ŵ���ҽ����������һֱ��һ���ԣ�û����֪���������\n��֪��Ϊʲô���������������С�\n");
	set("title", HIG"������ʿ"NOR);
	set("gender", "����");
	set("age", 80);
	set("int", 30);
	set("con", 30);

	set("max_qi", 903);
	set("max_jing", 870);
	set("eff_jingli", 1500);
	set("max_jingli", 1500);
	set("neili", 2000);
	set("max_neili", 2000);

	set_skill("literate", 300);
	set_skill("medicine", 400);
	set_skill("force", 200);
	set_skill("dodge", 200);
	set_skill("parry", 200);

	set("combat_exp", 1000000);
	set("shen_type", 1);

	setup();

	carry_object("/d/wuguan/obj/yinzhen")->wield();
	carry_object("/d/wuguan/obj/robe")->wear();

}