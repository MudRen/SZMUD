// hetaichong.c (kunlun)

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_ding();
string ask_su();

void create()
{
	set_name("��̫��", ({ "he taichong", "he" }));
	set("title", "����������");
	set("nickname", "��������");
	set("long",
		"���������������š����ｭ��������������̫�塣\n"
		"��Ȼ����Ѵ󣬵���Ȼ���ó�������ʱӢ��������\n");
	set("gender", "����");
	set("age", 40);
	set("attitude", "heroism");
        set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);

	set("max_qi", 2500);
	set("max_jing", 2000);
	set("max_jingli",3000);
	set("jingli",3000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 100);
        set("combat_exp", 1800000);
	set("score", 40000);

        set_skill("qinqi-shuhua", 200);
		set_skill("taoism",200);
        set_skill("literate", 200);
          set_skill("force", 260);
        set_skill("xuantian-wuji", 260);
          set_skill("zhentian-quan", 260);
          set_skill("dodge", 260);
        set_skill("taxue-wuhen", 260);
        set_skill("throwing", 230);
        set_skill("mantian-huayu", 260);
        set_skill("strike", 260);
        set_skill("kunlun-zhang", 260);
        set_skill("cuff", 260);
        set_skill("parry", 260);
        set_skill("sword", 260);
        set_skill("liangyi-jian", 260);
       
        map_skill("force", "xuantian-wuji");
		map_skill("strike", "kunlun-zhang");
            map_skill("cuff", "zhentian-quan");
	    map_skill("dodge", "taxue-wuhen");
	    map_skill("parry", "liangyi-jian");
            map_skill("throwing", "mantian-huayu");
	    map_skill("sword", "liangyi-jian");

        prepare_skill("strike", "kunlun-zhang");
        prepare_skill("cuff", "zhentian-quan");

	create_family("������", 4, "������");
	set("class", "taoist");

	set("inquiry",
		([
		    "���ǽ���" : "���Ǳ��Ų��⴫�ľ�ѧ��\n",
                     "ɥ�Ŷ�" : "��Ҫ����ʲô?��\n",
                      "Ͷ���ؾ�" : "��ȥ����ʦ�������ӡ�\n",
            "�����" : "���������ɿ�ɽ��ʦ��\n",
                      "���" : "С��������Ҫ�÷��������ˡ�\n",
                    "��԰" : "��������Ϊ��ô�����֬��(flower)�����ڻ�԰��\n",
     		"�ķ�" : (: ask_me :),
			"��ϰ֮" : (: ask_su :),
			"׷ɱ" : (: ask_ding :),
		]));

	set("book_count", 1);
	set("ding_count", 18);

	setup();
	carry_object("/d/kunlun/obj/sword.c")->wield();
	carry_object("/d/kunlun/obj/pao2.c")->wear();
}

void attempt_apprentice(object ob)
{
/*	 if((int)ob->query("shen")<0){
	 command("say ���������������������ɣ�"+RANK_D->query_respect(ob)+
				"��Ʒ��ʵ�����˻��ɡ�");
	 command("say "+RANK_D->query_respect(ob)+
				"�����Ȼ�ȥ�������°ɡ�");
	 return;
	 }
*/
	 if(ob->query("gender")=="Ů��"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"�Ϸ�ɲ�����Ů���ӣ���ȥ�Ұ���˰�.�");
	 return;
	 }
      
         if( ob->query("family/family_name") != "������" && ob->query("combat_exp") >= 100000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                        +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }

        if (ob->query("class")=="bonze") {
                command ("say ������һ���ճ�����Ϊͽ������ذɡ�");
                return;
        }

	    if ((string)ob->query("gender") == "����" && (int)ob->query_skill("pixie-jian",1) > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "���Ѿ����б�а����,�α��������ǽ���");
                return;
        }
                if ((int)ob->query_skill("qinqi-shuhua", 1) < 5) {
                command("say ��һ��Ӧ��ȥѧһЩ���ջ�������������ɽѧϰ��");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�����������黭�϶��µ㹦��");
                return;
        }
        
	 command("say �ðɣ��ұ������㣬ֻ����Ͷ��������֮����ð���ѧ�ա�");
	 command("recruit " + ob->query("id"));
}


string ask_me()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "������")
					 return RANK_D->query_respect(this_player()) +
					 "�뱾��������������֪�˻��Ӻ�̸��";
		  if (query("book_count") < 1)
					 return "�������ˣ������ľ��ѱ���ʦ�������ˡ�";
//          if(ob->query("gender")!="Ů��"||ob->query("per")<23)
//        	     	 return "�����ľ����������";
	 	  add("book_count", -1);
		  ob = new("/d/kunlun/obj/force-book.c");
		  ob->move(this_player());
		  return "�������б����ķ��������й����������ģ����û�ȥ�ú����У��пն�������Ŷ";
}

string ask_ding()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "������")
					 return RANK_D->query_respect(this_player()) +
					 "�뱾��������������֪�˻��Ӻ�̸��";
		
                   if(this_player()->query_skill("mantian-huayu",1) < 20)
  return "�Բ������ļһ��ʹ���˱��ŵĶ��Ű���ɥ�Ŷ���?��ȥ��Ϊʦ����,����ҹ�!";
		   
	if ( present("sangmen ding", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"���������ϲ���������ô����Ҫ�ˣ�";
		  if (query("ding_count") < 1)
					 return "ɥ�Ŷ��Ѹ�������ȥ׷ɱ��ϰ֮���ˣ���Ͳ���ȥ�ˡ�";
		  add("ding_count", -1);
		  this_player()->set_temp("kunlun/ding",1);
		  ob = new("/d/kunlun/obj/sangmending.c");
		  ob->move(this_player());
		  return "�������ԸΪʦ��Ч����������ƽʱһ�����࣬���ɥ�Ŷ������ȥ�ɡ�";
}
string ask_su()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "������")
					 return RANK_D->query_respect(this_player()) +
					 "�뱾��������������֪�˻��Ӻ�̸��";
		
		 if(this_player()->query_temp("kunlun/ding",1))
           return "�㻹����������ʲô��������ȥ׷��ϰ֮";
		  return "��ϰ֮��һﾹȻ��͵�����ɵ������񽣣����ɵ��ӱص�����׷ɱ��";
}
