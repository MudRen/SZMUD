// xfang.c (kunlun)

inherit NPC;

string ask_me_1(string name);

void create()
{
        set_name("�ӷ�", ({ "xing fang", "xing" }));
        set("gender", "Ů��" );
        set("age", 18);
        set("max_neili", 500);
        set("neili", 500);
        set("long", "���Ǻ�̫��ԭ����˰���浵�����ʹ�\n");

        set_temp("apply/attack", 10);
        set_temp("apply/defense", 10);
          set("combat_exp", 80000);
	set("shen_type", -1);
        set("str", 25);
        set("dex", 20);
        set("con", 18);
        set("int", 15);
        set("attitude","frindly");
        set_skill("force", 45 + random(10));
        set_skill("strike", 35 + random(20));
         set_skill("taxue-wuhen", 60 + random(20));
        set_skill("kunlun-zhang", 25 + random(20));
      set_skill("dodge", 60 + random(20));
        set_skill("parry", 45 + random(10));
        set_skill("xuantian-wuji", 45 + random(10));
map_skill("dodge","taxue-wuhen");
   map_skill("strike","kunlun-zhang");
        map_skill("force", "xuantian-wuji");
        prepare_skill("strike", "kunlun-zhang");
        set("inquiry", ([
		"���������" : (: ask_me_1, "honey" :)
        ]) );
          set("honey_count",5);
	set("jiuping_count",1);
        setup();
        
        set("chat_chance", 10);
        set("chat_msg", ({
"�ӷ����������������Ҳ̫������,�����������,�Ϸ���������!\n",
"�ӷ��ݺݵص�: ��һ��Ҫ����������ƶ�������������,�������Ǹ������ϸ��˾�����.\n",
        }) );
        carry_object("/d/kunlun/obj/cloth")->wear();
}

string ask_me_1(string name)
{
	mapping fam; 
	object ob;
	
	if (!(fam = this_player()->query("family")) || fam["family_name"] != "������")
		return RANK_D->query_respect(this_player()) + 
		"�뱾��������������֪�˻��Ӻ�̸��";

	if (  present(name, this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���Ǹո������һ������������Ҫ��?";

	if (query("honey_count") < 1)
		return "��Ǹ�������ò���ʱ�򣬱�ɽ������������Ѿ������ˡ�ʣ�µĶ�������������򼶾!";

	ob = new("/d/kunlun/obj/" + name);
	ob->move(this_player());

	add("honey_count", -1);

	message_vision("�ӷ���$Nһ��" + ob->query("name") + "��\n", this_player());

	return "�˾���֮����,������,��Ѫ,�ָ���������Ч,����(he)�˰ɡ�";
}
