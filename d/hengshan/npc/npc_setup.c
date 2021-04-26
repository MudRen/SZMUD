//Cracked by Roath
//udpdate by firefox 
void set_hp(int level,object ob) {
    ob->set("max_neili", level*12);
    ob->set("neili", level*12);
    ob->set("eff_jingli", level*10);
    ob->set("max_jingli", level*10);
    ob->set("jingli", level*10);
    ob->set("max_qi", level*12);
    ob->set("eff_qi", level*12);
    ob->set("qi", level*12);
    ob->set("max_jing", level*10);
    ob->set("eff_jing", level*10);
    ob->set("jing", level*10);
    ob->set("jiali", level/10);
}

string set_skills(string menpai, int exp, int skill_rate,object ob)
{
    int level;

    if (exp < 0 || skill_rate < 0) return;
    level = pow(10*exp, 0.333334);
    level = level*skill_rate/100;
    if (level < 20) level = 20;
    if (!stringp(menpai)) 
	menpai = menpai_list[random(sizeof(menpai_list))];

    ob->set("combat_exp", exp);
    ob->set_skill("force", level);
    ob->set_skill("dodge", level);
    ob->set_skill("parry", level);
    ob->set_skill("sword", level);
    ob->set_skill("blade", level);
    ob->set_skill("strike", level);
    ob->set_skill("cuff", level);
    ob->set_skill("finger", level);
    ob->set_skill("claw", level);
    ob->set_skill("club", level);
    ob->set_skill("kick", level);
    ob->set_skill("staff", level);
    ob->set_skill("whip", level);

    switch (menpai){
    case "huashan":
        ob->set_skill("huashan-jianfa", level);
        ob->set_skill("liangyi-dao", level);
        ob->set_skill("huashan-shenfa", level);
        ob->set_skill("zixia-gong", level);
	ob->set_skill("pishi-poyu", level);
	ob->set_skill("hunyuan-zhang", level);
 
        map_skill("force", "zixia-gong");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("strike", "hunyuan-zhang");
	map_skill("cuff", "pishi-poyu");
        map_skill("sword", "huashan-jianfa");
        map_skill("blade", "liangyi-dao");
        
        prepare_skill("cuff", "pishi-poyu");
        prepare_skill("strike", "hunyuan-zhang");
	
	ob->set("default_weapon", "/clone/weapon/gangjian");

	break;
    case "emei":
	ob->set_skill("huifeng-jian", level);
	ob->set_skill("yanxing-dao", level);
	ob->set_skill("jinding-zhang", level);
	ob->set_skill("tiangang-zhi", level);
	ob->set_skill("linji-zhuang", level);
	ob->set_skill("zhutian-bu", level);

	map_skill("force", "linji-zhuang");
	map_skill("sword", "huifeng-jian");
	map_skill("blade", "yanxing-dao");
	map_skill("strike", "jinding-zhang");
	map_skill("finger", "tiangang-zhi");
	map_skill("dodge", "zhutian-bu");
	map_skill("parry", "huifeng-jian");

        prepare_skill("finger", "tiangang-zhi");
        prepare_skill("strike", "jinding-zhang");
	ob->set("default_weapon", "/clone/weapon/gangdao");
	break;
    case "wudang":
        ob->set_skill("taiji-shengong", level);
        ob->set_skill("taiji-jian", level);
        ob->set_skill("tiyunzong", level);
	ob->set_skill("taiji-quan", level);
 
        map_skill("force", "taiji-shengong");
        map_skill("parry", "taiji-jian");
	map_skill("cuff", "taiji-quan");
        map_skill("dodge", "tiyunzong");
        map_skill("sword", "taiji-jian");
        
        prepare_skill("cuff", "taiji-quan");
	ob->set("default_weapon", "/clone/weapon/gangjian");
	break;
    case "shaolin":
        ob->set_skill("damo-jian", level);
        ob->set_skill("xiuluo-dao", level);
        ob->set_skill("wuchang-zhang", level);
        ob->set_skill("zui-gun", level);
        ob->set_skill("shaolin-shenfa", level);
        ob->set_skill("hunyuan-yiqi", level);
	ob->set_skill("yizhi-chan", level);
	ob->set_skill("banruo-zhang", level);
 
        map_skill("force", "hunyuan-yiqi");
        map_skill("dodge", "shaolin-shenfa");
        map_skill("parry", "damo-jian");
        map_skill("sword", "damo-jian");
        map_skill("blade", "xiuluo-dao");
        map_skill("club", "zui-gun");
        map_skill("staff", "wuchang-zhang");
        map_skill("finger", "yizhi-chan");
        map_skill("strike", "banruo-zhang");
        
        prepare_skill("finger", "yizhi-chan");
        prepare_skill("strike", "banruo-zhang");
	ob->set("default_weapon", "/clone/weapon/gangjian");
	break;

    case "gaibang":
        ob->set_skill("liuhe-dao", level);
        ob->set_skill("xiaoyaoyou", level);
        ob->set_skill("huntian-qigong", level);
	ob->set_skill("shexing-diaoshou", level);
 
        map_skill("force", "huntian-qigong");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "liuhe-dao");
        map_skill("blade", "liuhe-dao");
        map_skill("hand", "shexing-diaoshou");
        
        prepare_skill("hand", "shexing-diaoshou");
	ob->set("default_weapon", "/clone/weapon/gangdao");
	break;
    case "baituo":
        ob->set_skill("hamagong", level);
        ob->set_skill("lingshe-zhang", level);
	ob->set_skill("chanchubu", level);
	ob->set_skill("poison", level);
 
        map_skill("force", "hamagong");
        map_skill("dodge", "chanchubu");
        map_skill("parry", "lingshe-zhang");
        map_skill("strike", "hamagong");
        map_skill("staff", "lingshe-zhang");
        
        prepare_skill("strike", "hamagong");
	ob->set("default_weapon", "/clone/weapon/shezhang");
	break;
    case "hengshan":
        ob->set_skill("ding-force", level);
        ob->set_skill("hengshan-jian", level);
		ob->set_skill("lingxu-bu", level);
		ob->set_skill("buddhism", level);
 
        map_skill("force", "ding-force");
        map_skill("dodge", "lingxu-bu");
        map_skill("parry", "hengshan-jian");
        map_skill("sword", "hengshan-jian");
		ob->set("default_weapon", "/clone/weapon/changjian");
	break;
    case "songshan":
        ob->set_skill("songyang-qigong", level);
        ob->set_skill("songyang-zhang", level);
        ob->set_skill("songshan-jian", level);
		ob->set_skill("lingxu-bu", level);

        map_skill("force", "songyang-qigong");
        map_skill("dodge", "lingxu-bu");
        map_skill("parry", "songshan-jian");
        map_skill("sword", "songshan-jian");
        map_skill("strike", "songyang-zhang");
		ob->set("default_weapon", "/clone/weapon/changjian");
	break;
    case "taohua":
        ob->set_skill("bitao-xuangong", level);
        ob->set_skill("canglang-bian", level);
        ob->set_skill("luoying-shenfa", level);
	ob->set_skill("luoying-shenjian", level);
	ob->set_skill("xuanfeng-saoye", level);
	ob->set_skill("qimen-dunjia", level);
 
        map_skill("force", "bitao-xuangong");
        map_skill("dodge", "luoying-shenfa");
        map_skill("parry", "canglang-bian");
        map_skill("strike", "luoying-shenjian");
        map_skill("kick", "xuanfeng-saoye");
        map_skill("whip", "canglang-bian");
        
        prepare_skill("strike", "luoying-shenjian");
        prepare_skill("kick", "xuanfeng-saoye");
	ob->set("default_weapon", "/clone/weapon/changbian");
	break;

    case "xueshan":
        ob->set_skill("longxiang-banruo", level);
        ob->set_skill("xue-dao", level);
        ob->set_skill("jingang-chu", level);
	ob->set_skill("dashou-yin", level);
	ob->set_skill("yujiamu-quan", level);
	ob->set_skill("xueshitiao", level);
	ob->set_skill("mingwang-jian", level);
 
        map_skill("force", "longxiang-banruo");
        map_skill("dodge", "xueshitiao");
        map_skill("parry", "dashou-yin");
        map_skill("blade", "xue-dao");
        map_skill("sword", "mingwang-jian");
        map_skill("hand", "dashou-yin");
        map_skill("cuff", "yujiamu-quan");
        map_skill("staff", "jingang-chu");
        
        prepare_skill("cuff", "yujiamu-quan");
        prepare_skill("hand", "dashou-yin");
	ob->set("default_weapon", "/clone/weapon/gangzhang");
	break;

    case "xingxiu":
    default:
        ob->set_skill("huagong-dafa", level);
        ob->set_skill("zhaixinggong", level);
        ob->set_skill("chousui-zhang", level);
        ob->set_skill("sanyin-zhua", level);
        ob->set_skill("tianshan-zhang", level);
        ob->set_skill("poison", level);

	map_skill("force", "huagong-dafa");
	map_skill("strike", "chousui-zhang");
	map_skill("claw", "sanyin-zhua");
	map_skill("dodge", "zhaixinggong");
	map_skill("parry", "sanyin-zhua");
	map_skill("staff", "tianshan-zhang");

	prepare_skill("strike", "chousui-zhang");
	prepare_skill("claw", "sanyin-zhua");
	ob->set("default_weapon", "/clone/weapon/gangzhang");
	break;
    }
    return menpai;
}
