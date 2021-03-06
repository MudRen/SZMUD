/*-------------------------------------------------------------
** 文件名: doctor.c
** Copyright (c) 2000-2001
** 创建人: 武馆工作组
** 日  期: 2001/08/13
** 描  述: 神医
**-----------------------------------------------------------*/
#include <ansi.h>
inherit NPC;

string ask_me();

void create()
{
	set_name("神医", ({ "shen yi", "yi", "doctor" }));
	set("long", "他是江湖中传闻的神医，他的行踪一直是一个迷，没有人知道他在哪里。\n不知道为什么会出现在扬威武馆中。\n");
	set("title", HIG"江湖隐士"NOR);
	set("gender", "男性");
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