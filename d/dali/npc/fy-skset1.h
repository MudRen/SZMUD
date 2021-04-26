void skill_set1(object ob, int level)
{
	object weapon;
	switch (ob->query("title")) {
	case "������������" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("staff", level-35+random(10));
		ob->set_skill("poison", level-35+random(10));
		ob->set_skill("huagong-dafa", level-35+random(10));
		ob->set_skill("zhaixinggong", level-35+random(10));
		ob->set_skill("tianshan-zhang", level-35+random(10));
		ob->map_skill("staff","tianshan-zhang");
		ob->map_skill("dodge","zhaixinggong");
		ob->map_skill("parry", "tianshan-zhang");
		ob->map_skill("force","huagong-dafa");
		ob->set_skill("claw", level-35+random(10));
		ob->set_skill("sanyin-zhua", level-35+random(10));
		ob->set_skill("strike", level-35+random(10));
		ob->set_skill("chousui-zhang", level-35+random(10));
		map_skill("claw","sanyin-zhua");
		map_skill("strike","chousui-zhang");
		prepare_skill("claw","sanyin-zhua");
		prepare_skill("strike","chousui-zhang");
		weapon=new("/d/xingxiu/obj/gangzhang.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "��ɽ����ͽ" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("zixia-gong", level-35+random(10));
		ob->set_skill("huashan-shenfa", level-35+random(10));
		ob->map_skill("dodge","huashan-shenfa");
		ob->map_skill("force","zixia-gong");
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("pishi-poyu", level-35+random(10));
		ob->set_skill("strike", level-35+random(10));
		ob->set_skill("hunyuan-zhang", level-35+random(10));
		ob->map_skill("cuff","pishi-poyu");
		ob->map_skill("strike","hunyuan-zhang");
		ob->prepare_skill("cuff","pishi-poyu");
		ob->prepare_skill("strike","hunyuan-zhang");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("liangyi-dao", level-35+random(10));
			ob->map_skill("blade","liangyi-dao");
			ob->map_skill("parry","liangyi-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(10));
			ob->set_skill("huashan-jianfa", level-35+random(10));
			ob->map_skill("sword","huashan-jianfa");
			ob->map_skill("parry","huashan-jianfa");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "�䵱����ͽ" :
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("sword", level-35+random(10));
		ob->set_skill("taiji-shengong", level-35+random(10));
		ob->set_skill("taiji-jian", level-35+random(10));
		ob->set_skill("taiji-quan", level-35+random(10));
		ob->set_skill("tiyunzong", level-35+random(10));
		ob->map_skill("cuff","taiji-quan");
		ob->map_skill("sword","taiji-jian");
		ob->map_skill("dodge","tiyunzong");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("force","taiji-shengong");
		ob->prepare_skill("cuff","taiji-quan");
		weapon=new("/d/city/obj/gangjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "ѩɽ��С����" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("longxiang-banruo", level-35+random(10));
		ob->map_skill("force","longxiang-banruo");
		switch (random(2)) {
		case 0 :
			ob->set_skill("shenkongxing", level-35+random(10));
			ob->map_skill("dodge","shenkongxing");
			break;
		case 1 :
			ob->set_skill("xueshitiao", level-35+random(10));
			ob->map_skill("dodge","xueshitiao");
			break;
		}
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("yujiamu-quan", level-35+random(10));
		ob->set_skill("hand", level-35+random(10));
		ob->set_skill("dashou-yin", level-35+random(10));
		ob->map_skill("cuff","yujiamu-quan");
		ob->map_skill("hand","dashou-yin");
		ob->prepare_skill("cuff","yujiamu-quan");
		ob->prepare_skill("hand","dashou-yin");
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("xue-dao", level-35+random(10));
			ob->map_skill("blade","xue-dao");
			ob->map_skill("parry","xue-dao");
			weapon=new("/d/xueshan/obj/miandao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(10));
			ob->set_skill("mingwang-jian", level-35+random(10));
			ob->map_skill("sword","mingwang-jian");
			ob->map_skill("parry","mingwang-jian");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("staff", level-35+random(10));
			ob->set_skill("jingang-chu", level-35+random(10));
			ob->map_skill("staff","jingang-chu");
			ob->map_skill("parry","jingang-chu");
			weapon=new("/d/xueshan/obj/fachu.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "ؤ�����" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("strike", level-35+random(10));
		ob->set_skill("huntian-qigong", level-35+random(10));
		ob->set_skill("xiaoyaoyou", level-35+random(10));
		ob->set_skill("xianglong-zhang", level-35+random(10));
		ob->map_skill("dodge","xiaoyaoyou");
		ob->map_skill("force","huntian-qigong");
		ob->map_skill("strike","xianglong-zhang");
		ob->prepare_skill("strike","xianglong-zhang");
		ob->set_skill("stick", level-35+random(10));
		ob->set_skill("dagou-bang", level-35+random(10));
		ob->map_skill("stick","dagou-bang");
		ob->map_skill("parry","dagou-bang");
		weapon=new("/d/city/obj/zhubang.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "�嶾�̴���" :
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("hook", level-35+random(10));
		ob->set_skill("ruyi-gou", level-35+random(10));
		ob->set_skill("wuxing-quan", level-35+random(10));
		ob->set_skill("wuxingbu", level-35+random(10));
		ob->map_skill("cuff","wuxing-quan");
		ob->map_skill("hook","ruyi-gou");
		ob->map_skill("dodge","wuxingbu");
		ob->map_skill("parry", "ruyi-gou");
		ob->prepare_skill("cuff","wuxing-quan");
		weapon=new("/clone/weapon/hook.c");
		weapon->move(ob);
		weapon->wield();
		break;
	}
	return;
}

void skill_set2(object ob, int level)
{
	object weapon;
	switch (ob->query("title")) {
	case "�������ֶ�ɮ" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("hunyuan-yiqi", level-35+random(10));
		ob->set_skill("shaolin-shenfa", level-35+random(10));
		ob->map_skill("dodge","shaolin-shenfa");
		ob->map_skill("force","hunyuan-yiqi");
		switch (random(3)) {
		case 0 :
			ob->set_skill("finger", level-35+random(10));
			ob->set_skill("yizhi-chan", level-35+random(10));
			ob->set_skill("strike", level-35+random(10));
			ob->set_skill("banruo-zhang", level-35+random(10));
			ob->map_skill("finger","yizhi-chan");
			ob->map_skill("strike","banruo-zhang");
			ob->prepare_skill("finger","yizhi-chan");
			ob->prepare_skill("strike","banruo-zhang");
			break;
		case 1 :
			ob->set_skill("cuff", level-35+random(10));
			ob->set_skill("jingang-quan", level-35+random(10));
			ob->map_skill("cuff","jingang-quan");
			ob->prepare_skill("cuff","jingang-quan");
			break;
		case 2 :
			ob->set_skill("finger", level-35+random(10));
			ob->set_skill("nianhua-zhi", level-35+random(10));
			ob->set_skill("strike", level-35+random(10));
			ob->set_skill("sanhua-zhang", level-35+random(10));
			ob->map_skill("finger","nianhua-zhi");
			ob->map_skill("strike","sanhua-zhang");
			ob->prepare_skill("finger","nianhua-zhi");
			ob->prepare_skill("strike","sanhua-zhang");
			break;
		}
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("xiuluo-dao", level-35+random(10));
			ob->map_skill("blade","xiuluo-dao");
			ob->map_skill("parry","xiuluo-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(10));
			ob->set_skill("fumo-jian", level-35+random(10));
			ob->map_skill("sword","fumo-jian");
			ob->map_skill("parry","fumo-jian");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("club", level-35+random(10));
			ob->set_skill("zui-gun", level-35+random(10));
			ob->map_skill("club","zui-gun");
			ob->map_skill("parry","zui-gun");
			weapon=new("/clone/weapon/qimeigun.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "��ɽ����ͽ" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("zixia-gong", level-35+random(10));
		ob->set_skill("huashan-shenfa", level-35+random(10));
		ob->map_skill("dodge","huashan-shenfa");
		ob->map_skill("force","zixia-gong");
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("pishi-poyu", level-35+random(10));
		ob->set_skill("strike", level-35+random(10));
		ob->set_skill("hunyuan-zhang", level-35+random(10));
		ob->map_skill("cuff","pishi-poyu");
		ob->map_skill("strike","hunyuan-zhang");
		ob->prepare_skill("cuff","pishi-poyu");
		ob->prepare_skill("strike","hunyuan-zhang");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("liangyi-dao", level-35+random(10));
			ob->map_skill("blade","liangyi-dao");
			ob->map_skill("parry","liangyi-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(10));
			ob->set_skill("huashan-jianfa", level-35+random(10));
			ob->map_skill("sword","huashan-jianfa");
			ob->map_skill("parry","huashan-jianfa");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "�䵱����ͽ" :
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("sword", level-35+random(10));
		ob->set_skill("taiji-shengong", level-35+random(10));
		ob->set_skill("taiji-jian", level-35+random(10));
		ob->set_skill("taiji-quan", level-35+random(10));
		ob->set_skill("tiyunzong", level-35+random(10));
		ob->map_skill("cuff","taiji-quan");
		ob->map_skill("sword","taiji-jian");
		ob->map_skill("dodge","tiyunzong");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("force","taiji-shengong");
		ob->prepare_skill("cuff","taiji-quan");
		weapon=new("/d/city/obj/gangjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "ѩɽ������" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("longxiang-banruo", level-35+random(10));
		ob->map_skill("force","longxiang-banruo");
		switch (random(2)) {
		case 0 :
			ob->set_skill("shenkongxing", level-35+random(10));
			ob->map_skill("dodge","shenkongxing");
			break;
			case 1 :
			ob->set_skill("xueshitiao", level-35+random(10));
			ob->map_skill("dodge","xueshitiao");
			break;
		}
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("yujiamu-quan", level-35+random(10));
		ob->set_skill("hand", level-35+random(10));
		ob->set_skill("dashou-yin", level-35+random(10));
		ob->map_skill("cuff","yujiamu-quan");
		ob->map_skill("hand","dashou-yin");
		ob->prepare_skill("cuff","yujiamu-quan");
		ob->prepare_skill("hand","dashou-yin");
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("xue-dao", level-35+random(10));
			ob->map_skill("blade","xue-dao");
			ob->map_skill("parry","xue-dao");
			weapon=new("/d/xueshan/obj/miandao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(10));
			ob->set_skill("mingwang-jian", level-35+random(10));
			ob->map_skill("sword","mingwang-jian");
			ob->map_skill("parry","mingwang-jian");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("staff", level-35+random(10));
			ob->set_skill("jingang-chu", level-35+random(10));
			ob->map_skill("staff","jingang-chu");
			ob->map_skill("parry","jingang-chu");
			weapon=new("/d/xueshan/obj/fachu.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "�嶾������" :
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("hook", level-35+random(10));
		ob->set_skill("ruyi-gou", level-35+random(10));
		ob->set_skill("wuxing-quan", level-35+random(10));
		ob->set_skill("wuxingbu", level-35+random(10));
		ob->map_skill("cuff","wuxing-quan");
		ob->map_skill("hook","ruyi-gou");
		ob->map_skill("dodge","wuxingbu");
		ob->map_skill("parry", "ruyi-gou");
		ob->prepare_skill("cuff","wuxing-quan");
		weapon=new("/clone/weapon/hook.c");
		weapon->move(ob);
		weapon->wield();
		break;
	}
	return;
}

void skill_set3(object ob, int level)
{
	object weapon;
	switch (ob->query("title")) {
	case "�������ָ�ɮ" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("hunyuan-yiqi", level-35+random(10));
		ob->set_skill("shaolin-shenfa", level-35+random(10));
		ob->map_skill("dodge","shaolin-shenfa");
		ob->map_skill("force","hunyuan-yiqi");
		switch (random(3)) {
		case 0 :
			ob->set_skill("finger", level-35+random(10));
			ob->set_skill("yizhi-chan", level-35+random(10));
			ob->set_skill("strike", level-35+random(10));
			ob->set_skill("banruo-zhang", level-35+random(10));
			ob->map_skill("finger","yizhi-chan");
			ob->map_skill("strike","banruo-zhang");
			ob->prepare_skill("finger","yizhi-chan");
			ob->prepare_skill("strike","banruo-zhang");
			break;
		case 1 :
			ob->set_skill("cuff", level-35+random(10));
			ob->set_skill("jingang-quan", level-35+random(10));
			ob->map_skill("cuff","jingang-quan");
			ob->prepare_skill("cuff","jingang-quan");
			break;
		case 2 :
			ob->set_skill("finger", level-35+random(10));
			ob->set_skill("nianhua-zhi", level-35+random(10));
			ob->set_skill("strike", level-35+random(10));
			ob->set_skill("sanhua-zhang", level-35+random(10));
			ob->map_skill("finger","nianhua-zhi");
			ob->map_skill("strike","sanhua-zhang");
			ob->prepare_skill("finger","nianhua-zhi");
			ob->prepare_skill("strike","sanhua-zhang");
			break;
		}
		switch (random(3)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("cibei-dao", level-35+random(10));
			ob->map_skill("blade","cibei-dao");
			ob->map_skill("parry","cibei-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("whip", level-35+random(10));
			ob->set_skill("riyue-bian", level-35+random(10));
			ob->map_skill("whip","riyue-bian");
			ob->map_skill("parry","riyue-bian");
			weapon=new("/clone/weapon/changbian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 2 :
			ob->set_skill("club", level-35+random(10));
			ob->set_skill("zui-gun", level-35+random(10));
			ob->map_skill("club","zui-gun");
			ob->map_skill("parry","zui-gun");
			weapon=new("/clone/weapon/qimeigun.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "��ɽ����ͽ" :
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("zixia-gong", level-35+random(10));
		ob->set_skill("huashan-shenfa", level-35+random(10));
		ob->map_skill("dodge","huashan-shenfa");
		ob->map_skill("force","zixia-gong");
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("pishi-poyu", level-35+random(10));
		ob->set_skill("strike", level-35+random(10));
		ob->set_skill("hunyuan-zhang", level-35+random(10));
		ob->map_skill("cuff","pishi-poyu");
		ob->map_skill("strike","hunyuan-zhang");
		ob->prepare_skill("cuff","pishi-poyu");
		ob->prepare_skill("strike","hunyuan-zhang");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("liangyi-dao", level-35+random(10));
			ob->map_skill("blade","liangyi-dao");
			ob->map_skill("parry","liangyi-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("sword", level-35+random(10));
			ob->set_skill("huashan-jianfa", level-35+random(10));
			ob->map_skill("sword","huashan-jianfa");
			ob->map_skill("parry","huashan-jianfa");
			weapon=new("/d/city/obj/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "�䵱����ͽ" :
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level-35+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("sword", level-35+random(10));
		ob->set_skill("taiji-shengong", level-35+random(10));
		ob->set_skill("taiji-jian", level-35+random(10));
		ob->set_skill("taiji-quan", level-35+random(10));
		ob->set_skill("tiyunzong", level-35+random(10));
		ob->map_skill("cuff","taiji-quan");
		ob->map_skill("sword","taiji-jian");
		ob->map_skill("dodge","tiyunzong");
		ob->map_skill("parry", "taiji-jian");
		ob->map_skill("force","taiji-shengong");
		ob->prepare_skill("cuff","taiji-quan");
		weapon=new("/d/city/obj/gangjian.c");
		weapon->move(ob);
		weapon->wield();
		break;
	case "ѩɽ������" :
		ob->set_skill("dodge", level-40+random(5));
		ob->set_skill("force", level-40+random(5));
		ob->set_skill("parry", level-40+random(5));
		ob->set_skill("longxiang-banruo", level-35+random(5));
		ob->map_skill("force","longxiang-banruo");
		switch (random(2)) {
		case 0 :
			ob->set_skill("shenkongxing", level-40+random(5));
			ob->map_skill("dodge","shenkongxing");
			break;
			case 1 :
			ob->set_skill("xueshitiao", level-40+random(5));
			ob->map_skill("dodge","xueshitiao");
			break;
		}
		ob->set_skill("strike", level-35+random(10));
		ob->set_skill("huoyan-dao", level-35+random(10));
		ob->map_skill("strike","huoyan-dao");
		ob->prepare_skill("strike","huoyan-dao");
		switch (random(2)) {
		case 0 :
			ob->set_skill("blade", level-35+random(10));
			ob->set_skill("xue-dao", level-35+random(10));
			ob->map_skill("blade","xue-dao");
			ob->map_skill("parry","xue-dao");
			weapon=new("/d/city/obj/gangdao.c");
			weapon->move(ob);
			weapon->wield();
			break;
		case 1 :
			ob->set_skill("mingwang-jian", level-40+random(5));
			ob->set_skill("sword", level-40+random(10));
			ob->map_skill("sword","mingwang-jian");
			ob->map_skill("parry","mingwang-jian");
			weapon=new("/clone/weapon/gangjian.c");
			weapon->move(ob);
			weapon->wield();
			break;
		}
		break;
	case "�嶾������" :
		ob->set_skill("cuff", level-35+random(10));
		ob->set_skill("dodge", level-35+random(10));
		ob->set_skill("force", level+random(10));
		ob->set_skill("parry", level-35+random(10));
		ob->set_skill("hook", level-35+random(10));
		ob->set_skill("ruyi-gou", level-35+random(10));
		ob->set_skill("wuxing-quan", level-35+random(10));
		ob->set_skill("wuxingbu", level-35+random(10));
		ob->map_skill("cuff","wuxing-quan");
		ob->map_skill("hook","ruyi-gou");
		ob->map_skill("dodge","wuxingbu");
		ob->map_skill("parry", "ruyi-gou");
		ob->prepare_skill("cuff","wuxing-quan");
		weapon=new("/clone/weapon/hook.c");
		weapon->move(ob);
		weapon->wield();
		break;
	}
	return;
}
