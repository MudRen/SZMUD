// MODIFY BY SCATTER
// PERFORM CURRENTLY DISABLE
// Modify by FunBoo@sz
// ����ʦ������(Buwu@OPN)��age = (((int)query("mud_age")-864000) / 259200)) :: This is for set mudage after setup()

int set_skills(object me, string s_Menpai, int n_Age, int n_Skills_Level, int n_Xinfa_Level, int n_Str, int n_Int, int n_Con, int n_Dex, int n_Deathcount, int n_Pxj)
{
    int n_Exp, n_Lit_Level, n_Levels, n_Neili, n_Jingli;
	// Calculation for exp
	n_Levels = n_Skills_Level;
	n_Exp=n_Levels*n_Levels*n_Levels/10;
	// If menpai is 0, random assign menpai
	// if (!stringp(menpai))
	// menpai = menpai_list[random(sizeof(menpai_list))];

	if(n_Skills_Level>500)	// If skills is more than 400, xinfa is 400
	{
		n_Lit_Level = 500;
	}
	else						// else, xinfa is skill's level
	{
		n_Lit_Level=n_Skills_Level;
	}

    me->set_name(s_Menpai+"ľż", ({"muou", "mu ou"}));
	me->set("family/family_name", s_Menpai);
	
	me->set("age", n_Age);
	me->set("str", n_Str);
	me->set("int", n_Int);
	me->set("con", n_Con);
	me->set("dex", n_Dex);

	me->set("combat_exp",		n_Exp);
	me->set("death_count",		n_Deathcount);
	me->set("death_times",		n_Deathcount);
    me->set_skill("force",		n_Skills_Level);
    me->set_skill("dodge",		n_Skills_Level);
    me->set_skill("parry",		n_Skills_Level);
    me->set_skill("sword",		n_Skills_Level);
    me->set_skill("blade",		n_Skills_Level);
    me->set_skill("strike",		n_Skills_Level);
    me->set_skill("cuff",		n_Skills_Level);
    me->set_skill("finger",		n_Skills_Level);
    me->set_skill("claw",		n_Skills_Level);
    me->set_skill("club",		n_Skills_Level);
    me->set_skill("kick",		n_Skills_Level);
    me->set_skill("staff",		n_Skills_Level);
    me->set_skill("whip",		n_Skills_Level);
	me->set_skill("throwing",   n_Skills_Level);
	if(n_Pxj==1)			// If user need to use pxj
	{
		me->set_skill("pixie-jian", n_Skills_Level);
		me->set("canuse_cixin", 1);
		me->set("canuse_guimei", 1);
		me->set("gender", "����" );
	}
	
    switch (s_Menpai)
	{
    case "��ɽ��":
		me->set_skill("zhengqi-jue", n_Xinfa_Level);
		me->set_skill("ziyin-yin", n_Xinfa_Level);
		me->set_skill("literate", n_Lit_Level);

        me->set_skill("dugu-jiujian", n_Skills_Level);
		me->set_skill("huashan-jianfa", n_Skills_Level);
		me->set_skill("huashan-shenfa", n_Skills_Level);
		me->set_skill("hunyuan-zhang", n_Skills_Level);
        me->set_skill("liangyi-dao", n_Skills_Level);
		me->set_skill("pishi-poyu", n_Skills_Level);
        me->set_skill("zixia-gong", n_Skills_Level);

        me->map_skill("force", "zixia-gong");
        me->map_skill("dodge", "huashan-shenfa");
        me->map_skill("parry", "huashan-jianfa");
        me->map_skill("strike", "hunyuan-zhang");
		me->map_skill("cuff", "pishi-poyu");
        me->map_skill("sword", "huashan-jianfa");
        me->map_skill("blade", "liangyi-dao");
	break;

    case "������":
		me->set_skill("literate", n_Lit_Level);
		me->set_skill("mahayana", n_Xinfa_Level);
		me->set_skill("persuading", n_Xinfa_Level);

		me->set_skill("cuixin-zhang", n_Skills_Level);
		me->set_skill("emei-jian", n_Skills_Level);
		me->set_skill("feiyu-bian", n_Skills_Level);
		me->set_skill("jinding-zhang", n_Skills_Level);
		me->set_skill("jiuyin-zhao", n_Skills_Level);
		me->set_skill("linji-zhuang", n_Skills_Level);
		me->set_skill("yanxing-dao", n_Skills_Level);
		me->set_skill("tiangang-zhi", n_Skills_Level);
		me->set_skill("zhutian-bu", n_Skills_Level);
	
		me->map_skill("force", "linji-zhuang");
		me->map_skill("sword", "emei-jian");
		me->map_skill("blade", "yanxing-dao");
		me->map_skill("strike", "jinding-zhang");
		me->map_skill("finger", "tiangang-zhi");
		me->map_skill("dodge", "zhutian-bu");
		me->map_skill("parry", "emei-jian");
	break;

    case "�䵱��":
		me->set_skill("literate", n_Lit_Level);
		me->set_skill("taoism", n_Xinfa_Level);

		me->set("wudang/raozhi", 1);					// Let user can use raozhi-perform

        me->set_skill("mian-zhang", n_Skills_Level);
		me->set_skill("taiji-jian", n_Skills_Level);
		me->set_skill("taiji-quan", n_Skills_Level);
		me->set_skill("taiji-shengong", n_Skills_Level);
        me->set_skill("tiyunzong", n_Skills_Level);
		
 
        me->map_skill("force", "taiji-shengong");
        me->map_skill("parry", "taiji-jian");
		me->map_skill("cuff", "taiji-quan");
        me->map_skill("dodge", "tiyunzong");
        me->map_skill("sword", "taiji-jian");
	break;

    case "������":
		me->set_skill("literate", n_Lit_Level);
		me->set_skill("buddhism", n_Xinfa_Level);

        me->set_skill("banruo-zhang", n_Skills_Level);
		me->set_skill("cibei-dao", n_Skills_Level);
		me->set_skill("damo-jian", n_Skills_Level);
		me->set_skill("fengyun-shou", n_Skills_Level);
		me->set_skill("fumo-jian", n_Skills_Level);
		me->set_skill("hunyuan-yiqi", n_Skills_Level);
		me->set_skill("jingang-quan", n_Skills_Level);
		me->set_skill("longzhua-gong", n_Skills_Level);
		me->set_skill("luohan-quan", n_Skills_Level);
		me->set_skill("nianhua-zhi", n_Skills_Level);
		me->set_skill("pudu-zhang", n_Skills_Level);
		me->set_skill("qianye-shou", n_Skills_Level);
		me->set_skill("riyue-bian", n_Skills_Level);
		me->set_skill("sanhua-zhang", n_Skills_Level);
		me->set_skill("shaolin-shenfa", n_Skills_Level);
		me->set_skill("weituo-gun", n_Skills_Level);
		me->set_skill("wuchang-zhang", n_Skills_Level);
        me->set_skill("xiuluo-dao", n_Skills_Level);
        me->set_skill("yingzhua-gong", n_Skills_Level);
        me->set_skill("yizhi-chan", n_Skills_Level);
		me->set_skill("zui-gun", n_Skills_Level);
		 
        me->map_skill("force", "hunyuan-yiqi");
        me->map_skill("dodge", "shaolin-shenfa");
        me->map_skill("parry", "damo-jian");
        me->map_skill("sword", "damo-jian");
        me->map_skill("blade", "xiuluo-dao");
        me->map_skill("club", "zui-gun");
        me->map_skill("staff", "wuchang-zhang");
        me->map_skill("finger", "yizhi-chan");
        me->map_skill("strike", "banruo-zhang");
	break;

    case "ؤ��":
		me->set_skill("literate", n_Lit_Level);

		me->set_skill("dagou-bang", n_Skills_Level);
		me->set_skill("fengmo-zhang", n_Skills_Level);
		me->set_skill("huntian-qigong", n_Skills_Level);
		me->set_skill("liuhe-dao", n_Skills_Level);
		me->set_skill("shexing-diaoshou", n_Skills_Level);
		me->set_skill("xianglong-zhang", n_Skills_Level);
        me->set_skill("xiaoyaoyou", n_Skills_Level);
         
        me->map_skill("force", "huntian-qigong");
        me->map_skill("dodge", "xiaoyaoyou");
        me->map_skill("parry", "liuhe-dao");
        me->map_skill("blade", "liuhe-dao");
        me->map_skill("hand", "shexing-diaoshou");
	break;

    case "����ɽ":
        me->set_skill("poison", n_Xinfa_Level);
		me->set_skill("literate", n_Lit_Level);
		
		me->set_skill("chanchubu", n_Skills_Level);
		me->set_skill("hamagong", n_Skills_Level);
        me->set_skill("lingshe-quan", n_Skills_Level);
		me->set_skill("lingshe-zhang", n_Skills_Level);
		me->set_skill("shentuo-zhang", n_Skills_Level);
		 
        me->map_skill("force", "hamagong");
        me->map_skill("dodge", "chanchubu");
        me->map_skill("parry", "lingshe-zhang");
        me->map_skill("strike", "hamagong");
        me->map_skill("staff", "lingshe-zhang");
	break;

    case "�һ���":
		me->set_skill("music", n_Xinfa_Level);
		me->set_skill("qimen-dunjia", n_Xinfa_Level);
		me->set_skill("literate", n_Lit_Level);

        me->set_skill("bitao-xuangong", n_Skills_Level);
		me->set_skill("canglang-bian", n_Skills_Level);
		me->set_skill("lanhua-fuxue", n_Skills_Level);
		me->set_skill("luoying-shenfa", n_Skills_Level);
        me->set_skill("luoying-shenjian", n_Skills_Level);
		me->set_skill("tanzhi-shentong", n_Skills_Level);
		me->set_skill("xuanfeng-saoye", n_Skills_Level);
		me->set_skill("yuxiao-jian", n_Skills_Level);
 
        me->map_skill("force", "bitao-xuangong");
        me->map_skill("dodge", "luoying-shenfa");
        me->map_skill("parry", "canglang-bian");
        me->map_skill("strike", "luoying-shenjian");
        me->map_skill("kick", "xuanfeng-saoye");
        me->map_skill("whip", "canglang-bian");
	break;

    case "ѩɽ��":
		me->set("shen", -n_Exp);		// Make sure it got -shen
		me->set_skill("lamaism", n_Xinfa_Level);
		me->set_skill("literate", n_Lit_Level);

        me->set_skill("huoyan-dao", n_Skills_Level);
		me->set_skill("jingang-chu", n_Skills_Level);
		me->set_skill("longxiang-banruo", n_Skills_Level);
		me->set_skill("mingwang-jian", n_Skills_Level);
		me->set_skill("riyue-lun", n_Skills_Level);
		me->set_skill("shenkongxing", n_Skills_Level);
        me->set_skill("xue-dao", n_Skills_Level);
		me->set_skill("yujiamu-quan", n_Skills_Level);
 
        me->map_skill("force", "longxiang-banruo");
        me->map_skill("dodge", "shenkongxing");
        me->map_skill("parry", "xue-dao");
        me->map_skill("blade", "xue-dao");
        me->map_skill("sword", "mingwang-jian");
        me->map_skill("strike", "huoyan-dao");
        me->map_skill("staff", "jingang-chu");
	break;

    case "������":
    	me->set_skill("poison", n_Xinfa_Level);
		me->set_skill("literate", n_Lit_Level);

        me->set_skill("chousui-zhang", n_Skills_Level);
		me->set_skill("huagong-dafa", n_Skills_Level);
		me->set_skill("sanyin-zhua", n_Skills_Level);
		me->set_skill("tianshan-zhang", n_Skills_Level);
        me->set_skill("zhaixinggong", n_Skills_Level);
        
		me->map_skill("force", "huagong-dafa");
		me->map_skill("strike", "chousui-zhang");
		me->map_skill("claw", "sanyin-zhua");
		me->map_skill("dodge", "zhaixinggong");
		me->map_skill("parry", "sanyin-zhua");
		me->map_skill("staff", "tianshan-zhang");
	break;

	case "ȫ���":
		me->set_skill("taoism", n_Xinfa_Level);
		me->set_skill("literate", n_Lit_Level);

		me->set_skill("chunyang-quan", n_Skills_Level);
		me->set_skill("duanyun-bian", n_Skills_Level);
		me->set_skill("jinyangong", n_Skills_Level);
		me->set_skill("quanzhen-jian", n_Skills_Level);
		me->set_skill("sanhua-juding", n_Skills_Level);
        me->set_skill("xiantian-gong", n_Skills_Level);

		me->map_skill("dodge", "jinyangong");
		me->map_skill("parry", "quanzhen-jian");
		me->map_skill("force", "xiantian-gong");
	break;

	case "������":
		me->set_skill("taoism", n_Xinfa_Level);
		me->set_skill("literate", n_Lit_Level);
		me->set_skill("qinqi-shuhua", n_Xinfa_Level);
		
		me->set_skill("kunlun-zhang", n_Skills_Level);
		me->set_skill("liangyi-jian", n_Skills_Level);
		me->set_skill("mantian-huayu", n_Skills_Level);
		me->set_skill("taxue-wuhen", n_Skills_Level);
		me->set_skill("xuantian-wuji", n_Skills_Level);
        me->set_skill("zhentian-quan", n_Skills_Level);

		me->map_skill("dodge", "taxue-wuhen");
		me->map_skill("parry", "liangyi-jian");
		me->map_skill("force", "xuantian-wuji");
	break;

	case "��Ĺ��":
		me->set_skill("bee-training", n_Xinfa_Level);
		me->set_skill("literate", n_Lit_Level);
		me->set_skill("suxin-jue", n_Xinfa_Level);

		me->set_skill("feiyan-gong", n_Skills_Level);
		me->set_skill("kongming-quan", n_Skills_Level);
		me->set_skill("meinu-quan", n_Skills_Level);
		me->set_skill("quanzhen-jian", n_Skills_Level);
		me->set_skill("xiaohun-zhang", n_Skills_Level);
		me->set_skill("xuantie-jian", n_Skills_Level);
		me->set_skill("yunu-jianfa", n_Skills_Level);
        me->set_skill("yunu-xinjing", n_Skills_Level);

		me->map_skill("dodge", "feiyan-gong");
		me->map_skill("parry", "xuantie-jian");
		me->map_skill("force", "yunu-xinjing");
	break;

	case "����μ�":
		me->set_skill("literate", n_Lit_Level);
		me->set_skill("buddhism", n_Xinfa_Level);

		me->set_skill("duanjia-jian", n_Skills_Level);
		me->set_skill("duanshi-shenfa", n_Skills_Level);
		me->set_skill("feifeng-bian", n_Skills_Level);
		me->set_skill("jinyu-quan", n_Skills_Level);
		me->set_skill("kurong-changong", n_Skills_Level);
		me->set_skill("qingyan-zhang", n_Skills_Level);
		me->set_skill("yiyang-zhi", n_Skills_Level);

		me->map_skill("dodge", "duanshi-shenfa");
		me->map_skill("parry", "yiyang-zhi");
		me->map_skill("force", "kurong-changong");
	break;

	default:
	break;
    }

	// Set muou's Jingli and Neili, and full it:
	n_Neili = (int)me->query_skill("force")*me->query("con")*2/3;	// Get max neili value
	n_Jingli = (int)me->query_skill("force")*me->query("con")/2;	// Get max jingli value
	me->set("max_neili", n_Neili);
    me->set("neili", n_Neili);
    me->set("eff_jingli", n_Jingli);
    me->set("max_jingli", n_Jingli);
    me->set("jingli", n_Jingli);
    return 1;
}
