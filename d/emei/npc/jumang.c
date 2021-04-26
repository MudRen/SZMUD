// Code of ShenZhou
// animal: jumang.c

inherit NPC;

void create()
{
        set_name("����", ({ "ju mang", "she", "mang", "ju mang" }) );
        set("race", "����");
        set("age", 100);
        set("long", "һ����ڴ�ϸ������ͷ�����������ɶ೤��\n");
        set("attitude", "peaceful");

        set("str", 32);
        set("cor", 36);
	set("max_jing", 1000);
	set("max_qi", 2000);

        set("limbs", ({ "ͷ��", "����", "�ߴ�", "β��" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 50000);

        set_temp("apply/attack", 80);
        set_temp("apply/damage", 80);
        set_temp("apply/dodge", 80);
        set_temp("apply/armor", 80);

        setup();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && !is_fighting()
             && random(ob->query_kar() + ob->query_per()) < 40) {
                        remove_call_out("kill_ob");
                        call_out("kill_ob", 1, ob); 
        }
}

void die()
{
        object ob;
        message_vision("$Nȫ��Ť�������ڻ��裬��춽�ֱ�����ˡ�\n", this_object());
        ob = new(DRUG_D("mangshe-dan"));
        ob->move(environment(this_object()));
        destruct(this_object());
}
