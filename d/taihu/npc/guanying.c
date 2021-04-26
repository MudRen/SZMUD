// Code of ShenZhou
// Npc: 
// Date: 

inherit NPC;

string ask_for_ruhuo();
int do_decide();
void create()
{
	set_name("½��Ӣ", ({
		"lu guanying",
		"guanying",
		"lu",
	}));
	set("title", "����ׯ��ׯ��");
	set("long",
		"���ǹ���ׯ��ׯ��½��Ӣ�������������������׳����\n"
		"���ж�֮�����Ķ��ţ�ǫ������һ�������ӵܷ緶��\n"
		"����������̫��Ⱥ�������죬��֪�����Ǽ١�\n"
	);


	set("gender", "����");
	set("attitude", "heroism");

	set("age", 23);
	set("shen_type",0);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 500);
	set("max_jing", 400);
	set("neili", 1000);
	set("max_neili", 1000);
	set("combat_exp", 100000);
	set("score", 100);
	

	set_skill("force", 60);
	set_skill("hunyuan-yiqi", 60);
	set_skill("dodge", 60);
	set_skill("shaolin-shenfa", 60);
	set_skill("cuff", 60);
	set_skill("luohan-quan", 60);
	set_skill("parry", 60);
	set_skill("blade",60);
	set_skill("cibei-dao",60);

	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");

        set("inquiry",([
                "����ׯ"  : (: ask_for_ruhuo :),
        ]));

	setup();

        carry_object("/d/taihu/obj/cloth")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}

void init()
{
        add_action("do_decide", "decide");
}

string ask_for_ruhuo()
{
        object me = this_player();    
    	mapping myfam = (mapping)me->query("family");

	if (  present("shu xin", this_player()) )
		return RANK_D->query_respect(me) + "����ô���ڻ�ûȥ����ׯ��\n";

      if ( myfam ) {
	if (  myfam["family_name"] == "�һ���"  )
		return RANK_D->query_respect(me) + "��Ȼ������־ͬ���ϣ��Ժ󲻷����д��д�\n";
      }
	me->set_temp("pending/ruhuo", 1);
        return "����ׯ�������¾Ӵ������"+RANK_D->query_respect(me)+"����(decide)���ҿ�����һ���Ϊ������\n";
}

int do_decide()
{
        object ob;
        if( !this_player()->query_temp("pending/ruhuo") )
                return 0;

        message_vision(
                "$N˫�ֱ�ȭ������������ׯ�������ˡ�\n", this_player());
        this_player()->delete_temp("pending/ruhuo");
//RYU!!! DO NOT DELETE PLAYER'S CLASS!!!!!!!! 
	ob=new("/d/taihu/obj/shuxin");
	ob->move(this_player());

	message_vision("½��Ӣ˵�����ã�\n½��Ӣ��$Nһ�����š�\n", this_player());

	message_vision("½��Ӣ˵������λ"+RANK_D->query_respect(this_player())+"���ȵ���ׯ�̺����գ��Ժ���ͼ����\n",this_player());
	return 1;
}
