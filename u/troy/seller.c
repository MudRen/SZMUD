//С��
//troy 2001.12


inherit NPC;

void create()
{
	set_name("С��", ({ "xiao si", "si" }) );
	set("gender", "����" );
	set("age", 32);
	set("long",
"�����Խ�ɽׯ�Ŀ���С�ˣ�ר�ű��������Ʒ��\n");
	set("shen_type", 1);
	set("combat_exp", 300);
        set("str", 17);
        set("dex", 20);
        set("con", 17);
        set("int", 22);
	set("attitude", "peaceful");
	setup();
        carry_object("clone/misc/cloth")->wear();
	}


