// Code of ShenZhou
// 
// 
inherit NPC;

int accept_object(object me, object obj);
void create()
{
	set_name("�Ҷ�", ({ "jia ding", "ding" }));
	set("long", "һ����ʮ��ͷ��С���ӣ�����ʵ��˫Ŀ�����ƺ��������깦��\n");
	set("gender", "����");
	set("age", 25);

	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("stick", 30);
	set_skill("staff", 30);
	set_skill("sword", 30);
	set_skill("blade", 30);	
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 5);

	set("combat_exp", 10000);
	set("shen_type", 1);
	setup();

	switch( random(4) )
        {
                case 0:
                       carry_object("/d/city/obj/gangjian")->wield();
                       break;
                case 1:
                       carry_object("/d/city/obj/gangdao")->wield();
                       break;
                case 2:
                       carry_object("/d/xingxiu/obj/gangzhang")->wield();
                       break;
                case 3:
                       carry_object("/d/city/obj/zhubang")->wield();
		       break;		
	}
}

int accept_object(object me, object obj)
{
      if((string)obj->query("name") == "����") {
		command("bow "+me->query("id"));
		message_vision("�Ҷ�˵����"+RANK_D->query_respect(me)+"ԭ������ׯ�������ѣ�������\n",me);
		me->set_temp("guiyun",1);
	}
	return 0;
}
