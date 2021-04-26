// bashuxian.c (kunlun)

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_qupu();

void create()
{
	set_name("�����", ({ "ban shuxian", "ban" }));
	set("title", "���������ŷ���");
	set("long",
		"���������������š����ｭ��������������̫��ķ��ˡ�\n"
		"����һ����ĸߴ�İ���Ů�ӣ�ͷ�����ף�˫Ŀ������ü�ļ����ɷ����\n");
	set("gender", "Ů��");
	set("age", 44);
	set("attitude", "heroism");
        set("shen_type", 1);
	set("str", 26);
	set("int", 24);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 4000);
	set("max_jingli", 4000);
	set("jingli", 4000);
    set("max_jing", 1000);
	set("neili", 5500);
	set("max_neili", 5500);
	set("jiali", 50);
	set("combat_exp", 1800000);
	set("score", 40000);

    set_skill("qinqi-shuhua", 200);
	set_skill("taoism",200);
    set_skill("literate", 200);
	set_skill("force", 220);
    set_skill("xuantian-wuji", 220);
    set_skill("cuff", 220);
    set_skill("zhentian-quan", 220);
    set_skill("dodge", 220);
	set_skill("taxue-wuhen", 220);
    set_skill("strike", 220);
    set_skill("kunlun-zhang", 220);
	set_skill("parry", 220);
        set_skill("throwing", 220);
        set_skill("mantian-huayu", 220);
	set_skill("sword", 220);
    set_skill("liangyi-jian", 220);
	
	
	map_skill("force", "xuantian-wuji");
	
	map_skill("strike", "kunlun-zhang");
	map_skill("dodge", "taxue-wuhen");
        map_skill("cuff", "zhentian-quan");
    map_skill("parry", "liangyi-jian");
	map_skill("sword", "liangyi-jian");
        map_skill("throwing", "mantian-huayu");
    prepare_skill("strike", "kunlun-zhang");
    prepare_skill("cuff", "zhentian-quan");

	create_family("������", 4, "���ŷ���");
	set("class", "taoist");

		set("inquiry",
		([  
            "���ǽ���" : "���Ǳ��Ų��⴫�ľ�ѧ��\n",
            "���ǽ�" : "���Ǳ��Ų��⴫�ľ�ѧ��\n",
              "���" : "�����Ҫ����Ů�ˣ�����һ���һ�ɱ������\n",
			"��̫��" : "�����ҵ��ɷ�\n",
		    "�����" : "���Ǳ������š�\n",
		    "�ؼ�" : (: ask_me :),
                    "����" : (: ask_qupu :),
		]));

	set("book_count", 1);

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
	 if ((string)ob->query("gender") != "Ů��") {
                command("say ��ֻ��Ů���ӣ�" + RANK_D->query_respect(ob) + "���ǰ��������������°ɡ�");
                return;
        } 
                if ((int)ob->query_skill("qinqi-shuhua", 1) < 5) {
                command("say �����������������ٽ�˫����");
                command("say " + RANK_D->query_respect(ob) +
                        "�Ƿ�Ӧ�����������黭�϶��µ㹦��");
                return;
        }

	 if( ob->query("family/family_name") != "������" && ob->query("combat_exp") >= 100000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "��"
                        +ob->query("family/family_name")+"���֣����ɿɲ���������");
                return;
        }

	 command("say �ðɣ��Ժ���͸���ѧ�书�ɣ�����ð���ѧ�գ�����������");
	 command("recruit " + ob->query("id"));
}


string ask_me()
{
		  mapping fam;
		  object ob , me = this_player();
		  


		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "������")
					 return RANK_D->query_respect(this_player()) +
					 "�뱾��������������֪�˻��Ӻ�̸��";
//			 if(ob->query("gender")=="����")
//        	     	 return "�����߿����ҿ���������Щ�����˾ͷ���";
//                    if (query("book_count") < 1)
                                         return "���Ǹ����ĺ�̫�������ˡ�";
//                    add("book_count", -1);
//                 ob = new("/d/kunlun/obj/lyj-book");
//                    CHANNEL_D->do_channel(me, "rumor", sprintf("%sŪ��һ�����ǽ��ס�", me->query("name")));
//                    ob->move(me); 
//                    return "��ʦ���������Ȿ�����ǽ��ĵá������û�ȥ�ú����С�";
}
string ask_qupu()
{
		  mapping fam;
		  object ob , me = this_player();
		  


		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "������")
					 return RANK_D->query_respect(this_player()) +
					 "�뱾��������������֪�˻��Ӻ�̸��";
		  if (query("book_count") < 0)
					 return "�������ˣ����ɵ������ѱ���ʦ�������ˡ�";
		  add("book_count", -1);
		  ob = new("/d/kunlun/obj/qupu.c");
		  ob->move(this_player());
		  return "���������Լ���д�����ף����û�ȥ�ú���ϰһ�¡�";
}

