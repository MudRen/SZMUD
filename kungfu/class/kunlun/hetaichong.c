// hetaichong.c (kunlun)

inherit NPC;
inherit F_MASTER;
string ask_me();
string ask_ding();
string ask_su();

void create()
{
	set_name("ºÎÌ«³å", ({ "he taichong", "he" }));
	set("title", "À¥ÂØÅÉÕÆÃÅ");
	set("nickname", "ÌúÇÙÏÈÉú");
	set("long",
		"Ëû¾ÍÊÇÀ¥ÂØÅÉÕÆÃÅ¡¢ÃûÑï½­ºşµÄÌúÇÙÏÈÉúºÎÌ«³å¡£\n"
		"ËäÈ»Äê¼ÍÒÑ´ó£¬µ«ÈÔÈ»¿´µÃ³öËûÄêÇáÊ±Ó¢¿¡äìÈ÷¡£\n");
	set("gender", "ÄĞĞÔ");
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

	create_family("À¥ÂØÅÉ", 4, "ÕÆÃÅÈË");
	set("class", "taoist");

	set("inquiry",
		([
		    "Á½ÒÇ½£·¨" : "ÄÇÊÇ±¾ÃÅ²»Íâ´«µÄ¾øÑ§¡£\n",
                     "É¥ÃÅ¶¤" : "ÄãÒªÕâ×öÊ²Ã´?¡£\n",
                      "Í¶ÖÀÃØ¾÷" : "ÄãÈ¥ÕÒÎÒÊ¦µÜÎ÷»ª×Ó¡£\n",
            "ºÎ×ãµÀ" : "ÊÇÎÒÀ¥ÂØÅÉ¿ªÉ½×æÊ¦¡£\n",
                      "Îå¹Ã" : "Ğ¡µãÉù£¬²»ÒªÈÃ·òÈËÌı¼ûÁË¡£\n",
                    "»¨Ô°" : "ÎÒÔÚÎ÷ÓòÎªÎå¹Ã´øµÄÁéÖ¬À¼(flower)¶¼ÖÖÔÚ»¨Ô°¡£\n",
     		"ĞÄ·¨" : (: ask_me :),
			"ËÕÏ°Ö®" : (: ask_su :),
			"×·É±" : (: ask_ding :),
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
	 command("say ÎÒÀ¥ÂØÄËÊÇÌÃÌÃÃûÃÅÕıÅÉ£¬"+RANK_D->query_respect(ob)+
				"µÄÆ·µÂÊµÔÚÁîÈË»³ÒÉ¡£");
	 command("say "+RANK_D->query_respect(ob)+
				"»¹ÊÇÏÈ»ØÈ¥×öµãÉÆÊÂ°É¡£");
	 return;
	 }
*/
	 if(ob->query("gender")=="Å®ĞÔ"){
	 command("fear");
	 command("say "+RANK_D->query_respect(ob)+
				"ÀÏ·ò¿É²»¸ÒÊÕÅ®µÜ×Ó£¬ÄãÈ¥ÕÒ°à·òÈË°É.£");
	 return;
	 }
      
         if( ob->query("family/family_name") != "À¥ÂØÅÉ" && ob->query("combat_exp") >= 100000 ) {
                command ("say " + RANK_D->query_respect(this_player()) + "ÊÇ"
                        +ob->query("family/family_name")+"¸ßÊÖ£¬±¾ÅÉ¿É²»¸ÒÊÕÁô£¡");
                return;
        }

        if (ob->query("class")=="bonze") {
                command ("say À¥ÂØÅÉÒ»Ïò²»ÊÕ³ö¼ÒÈËÎªÍ½£¬ÄãÇë»Ø°É¡£");
                return;
        }

	    if ((string)ob->query("gender") == "ÎŞĞÔ" && (int)ob->query_skill("pixie-jian",1) > 1 ) {
                command("say " + RANK_D->query_respect(ob) + "ÄãÒÑ¾­ĞŞĞĞ±ÙĞ°½£·¨,ºÎ±ØÔÚÁ·Á½ÒÇ½£¡£");
                return;
        }
                if ((int)ob->query_skill("qinqi-shuhua", 1) < 5) {
                command("say ÄãÒ»µãÓ¦¸ÃÈ¥Ñ§Ò»Ğ©ÇÙÒÕ»­ÒÕÔÚÀ´ÎÒÀ¥ÂØÉ½Ñ§Ï°¡£");
                command("say " + RANK_D->query_respect(ob) +
                        "ÊÇ·ñ»¹Ó¦¸ÃÏÈÔÚÇÙÆåÊé»­ÉÏ¶àÏÂµã¹¦·ò£¿");
                return;
        }
        
	 command("say ºÃ°É£¬ÎÒ±ãÊÕÏÂÄã£¬Ö»ÊÇÄãÍ¶ÈëÎÒÃÅÏÂÖ®ºó£¬ĞëµÃ°²ĞÄÑ§ÒÕ¡£");
	 command("recruit " + ob->query("id"));
}


string ask_me()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "À¥ÂØÅÉ")
					 return RANK_D->query_respect(this_player()) +
					 "Óë±¾ÅÉËØÎŞÀ´Íù£¬²»Öª´Ë»°´ÓºÎÌ¸Æğ£¿";
		  if (query("book_count") < 1)
					 return "ÄãÀ´ÍíÁË£¬±¾ÅÉĞÄ¾­ÒÑ±»ÄãÊ¦ĞÖÄÃ×ßÁË¡£";
//          if(ob->query("gender")!="Å®ĞÔ"||ob->query("per")<23)
//        	     	 return "±¾ÅÉĞÄ¾­²»ÔÚÎÒÕâÀï¡£";
	 	  add("book_count", -1);
		  ob = new("/d/kunlun/obj/force-book.c");
		  ob->move(this_player());
		  return "ÎÒÕâÀïÓĞ±¾¡¸ĞÄ·¨¡¹£¬ÊÇÓĞ¹ØÍÂÄÅÎüÆøµÄ£¬ÄãÄÃ»ØÈ¥ºÃºÃ×êÑĞ£¬ÓĞ¿Õ¶àÀ´ÕÒÎÒÅ¶";
}

string ask_ding()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "À¥ÂØÅÉ")
					 return RANK_D->query_respect(this_player()) +
					 "Óë±¾ÅÉËØÎŞÀ´Íù£¬²»Öª´Ë»°´ÓºÎÌ¸Æğ£¿";
		
                   if(this_player()->query_skill("mantian-huayu",1) < 20)
  return "×Ô²»Á¿Á¦µÄ¼Ò»ï£¬ÄÜÊ¹µÄÁË±¾ÃÅµÄ¶ÀÃÅ°µÆ÷É¥ÃÅ¶¤Âğ?±ğÈ¥¸øÎªÊ¦¶ªÁ³,¿ì¸øÎÒ¹ö!";
		   
	if ( present("sangmen ding", this_player()) )
		return RANK_D->query_respect(this_player()) + 
		"ÄãÏÖÔÚÉíÉÏ²»ÊÇÓĞÂğ£¬ÔõÃ´ÓÖÀ´ÒªÁË£¿";
		  if (query("ding_count") < 1)
					 return "É¥ÃÅ¶¤ÒÑ¸øÁËÎÒÅÉÈ¥×·É±ËÕÏ°Ö®µÄÈË£¬Äã¾Í²»ÓÃÈ¥ÁË¡£";
		  add("ding_count", -1);
		  this_player()->set_temp("kunlun/ding",1);
		  ob = new("/d/kunlun/obj/sangmending.c");
		  ob->move(this_player());
		  return "ÄãÈç´Ë×ÔÔ¸ÎªÊ¦ÃÅĞ§Á¦£¬²»Í÷ÎÒÆ½Ê±Ò»·¬ÔÔÅà£¬Õâ°ÑÉ¥ÃÅ¶¤Äã¾ÍÄÃÈ¥°É¡£";
}
string ask_su()
{
		  mapping fam;
		  object ob;

		  if (!(fam = this_player()->query("family"))
		 || fam["family_name"] != "À¥ÂØÅÉ")
					 return RANK_D->query_respect(this_player()) +
					 "Óë±¾ÅÉËØÎŞÀ´Íù£¬²»Öª´Ë»°´ÓºÎÌ¸Æğ£¿";
		
		 if(this_player()->query_temp("kunlun/ding",1))
           return "Äã»¹´ıÔÚÕâÀï×öÊ²Ã´£¬»¹²»¿ìÈ¥×·ËÕÏ°Ö®";
		  return "ËÕÏ°Ö®Õâ¼Ò»ï¾¹È»¸ÒÍµ¿´±¾ÅÉµÄÁ½ÒÇÉñ½££¬ÎÒÅÉµÜ×Ó±Øµ±½«Æä×·É±¡£";
}
