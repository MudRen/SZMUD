// Code of ShenZhou
// Jay 10/7/96

inherit NPC;

void create()
{
        set_name("�Ů", ({ "binu" }));
        set("long", "һ����ʮ�������װŮ�ӣ���ò���㣬��ü���۽�͸��һ��а����\n");
        set("gender", "Ů��");
        set("age", 22);

        set_skill("hand", 20);
	set_skill("shexing-diaoshou", 20);
        set_skill("dodge", 20);
	set_skill("chanchubu", 20);
        set_skill("parry", 20);
        set_skill("force", 20);
	set_skill("hamagong", 20);
	set_skill("training",30);
	map_skill("hand","shexing-diaoshou");
        map_skill("dodge","chanchubu");
	map_skill("force","hamagong");
	prepare_skill("hand","shexing-diaoshou");

        set("str", 28);
        set("int", 21);
        set("con", 27);
        set("dex", 21);

        set("max_neili", 200);
        set("jiali", 10);
        set("combat_exp", 5000);

        set("attitude", "peaceful");
        set("shen_type", -1);

        create_family("����ɽ", 4 , "����");
	setup();
        carry_object("/d/baituo/obj/wcloth")->wear();
}

void attempt_apprentice(object ob)
{
        command("shake");
        command("say ��ֻ�Ǹ�С�Ů��������ͽ��");
        return;
}

