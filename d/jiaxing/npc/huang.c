// Code of ShenZhou
// Jay 8/9/96

inherit NPC;

void create()
{
        set_name("���ӹ�",({ "huangzhong gong","gong" }) );
        set("gender", "����");
        set("age", 65);
	set("long",
		"������������ϵļ��ⶼ���˽�ȥ��ֱ��һ�����ã�"
		"˫Ŀȴ��������\n");
       // set("nickname","");
        set("title","÷ׯ��ׯ��");
        set("combat_exp", 90000);
        set("shen_type", 0);
        set("attitude", "friendly");
        set_skill("unarmed", 90);
	set_skill("force",90);
        set_skill("parry", 90);
        set_skill("dodge", 90);
	set_skill("staff",90);

	set("max_neili",500);
	set("neili",500);
	set("jiali",45);


	set("mz/toy","����ɢ");
	set("mz/set","huang");
	set("mz/need","heibai");
	set("mz/needname","��ׯ��");
        setup();
        carry_object("/clone/misc/cloth")->wear();
	carry_object(__DIR__"obj/yaoqin")->wield();
}

void fightwin(object who)
{
	object where = environment(this_object());

	message_vision("���ӹ������ϵı��ȣ����𴲰壬¶��һ�������󶴡�\n\n",
		who);
        command("say �����б��£��������÷ׯ�����λ�ڵ������ӵĸ��ֱȱȡ�");

	call_out("create_exit",1,where);
}

void create_exit(object where)
{
	where->set("exits/enter","/d/jiaxing/didao1");
}
#include "mzfight.h"



