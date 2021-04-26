inherit NPC;

string *yangwhere = ({
    "扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州",
	"扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州",
	"扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州",
	"扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州",
	"扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州",
	"扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州",
	"扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州",
	"扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州",
	"扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州",
	"扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州","扬州",
	"泉州","泉州","泉州","泉州","泉州","泉州","泉州","泉州","泉州","泉州",
	"泉州","泉州","泉州","泉州","泉州","泉州","泉州","泉州","泉州","泉州",
	"泉州","泉州","泉州","泉州","泉州","泉州","泉州","泉州","泉州","泉州",
	"泉州","泉州","泉州","泉州",
	"北京","北京","北京","北京","北京","北京","北京","北京","北京","北京",
	"北京","北京","北京","北京","北京","北京","北京","北京","北京","北京",
	"北京","北京","北京","北京","北京","北京","北京","北京",
       });

string *yangpath = ({
    "/d/city/guangchang",
	"/d/city/beidajie1",
	"/d/city/beidajie2",
	"/d/city/beijiao1",
	"/d/city/beijiao2",
	"/d/city/beijiao3",
	"/d/city/beijiao4",
	"/d/city/beimen",
	"/d/city/biaoju",
	"/d/city/bingqiku",
	"/d/city/bingyin",
	"/d/city/bingyindamen",
	"/d/city/caizhu",
	"/d/city/cangshuge",
	"/d/city/chaguan",
	"/d/city/chaguan1",
	"/d/city/dalao",
	"/d/city/damo",
	"/d/city/dangpu",
	"/d/city/datang",
	"/d/city/datiepu",
	"/d/city/dayuan",
	"/d/city/dayuan1",
	"/d/city/dongdajie1",
	"/d/city/dongdajie2",
	"/d/city/dongdajie3",
	"/d/city/dongjiao1",
	"/d/city/dongjiao2",
	"/d/city/dongjiao3",
	"/d/city/dongjiao4",
	"/d/city/dongmen",
	"/d/city/dongnanjie",
	"/d/city/dongting",
	"/d/city/dongxiang",
	"/d/city/duchang",
	"/d/city/duchang2",
	"/d/city/eproom",
	"/d/city/ft_datang",
	"/d/city/ft_room1",
	"/d/city/ftb_mishi",
	"/d/city/furong",
	"/d/city/guopintan",
	"/d/city/houyuan",
	"/d/city/huadian",
	"/d/city/huayuan",
	"/d/city/itembank",
	"/d/city/jail",
	"/d/city/jiuguan",
	"/d/city/jiuguan2",
	"/d/city/jujinge",
	"/d/city/kantai",
	"/d/city/kantai2",
	"/d/city/kedian",
	"/d/city/kedian2",
	"/d/city/kedian3",
	"/d/city/leitai",
	"/d/city/leitai2",
	"/d/city/lichun2",
	"/d/city/lichun_e",
	"/d/city/lichun_n",
	"/d/city/lichun_s",
	"/d/city/lichun_w",
	"/d/city/lichunyuan",
	"/d/city/majiu",
	"/d/city/meigui",
	"/d/city/minwu1",
	"/d/city/minwu2",
	"/d/city/mipu",
	"/d/city/mjroom",
	"/d/city/mjroom1",
	"/d/city/mjroom2",
	"/d/city/mjroom3",
	"/d/city/mjroom4",
	"/d/city/mudan",
	"/d/city/nandajie1",
	"/d/city/nandajie2",
	"/d/city/nandajie3",
	"/d/city/nanjiao1",
	"/d/city/nanjiao2",
	"/d/city/nanjiao3",
	"/d/city/nanjiao4",
	"/d/city/nanmen",
	"/d/city/neforest",
	"/d/city/neizhai",
	"/d/city/nproom",
	"/d/city/nwforest",
	"/d/city/qianzhuang",
	"/d/city/qianzhuang",
	"/d/city/qiyuan1",
	"/d/city/qiyuan2",
	"/d/city/qiyuan3",
	"/d/city/qiyuan4",
	"/d/city/quanzhou",
	"/d/city/seforest",
	"/d/city/seforest1",
	"/d/city/seforest2",
	"/d/city/xidajie1",
	"/d/city/xidajie2",
	"/d/city/xidajie3",
    "/d/quanzhou/zhongxin",
	"/d/quanzhou/minzai2",
	"/d/quanzhou/minzai1",
	"/d/quanzhou/minzai2",
	"/d/quanzhou/neitang",
	"/d/quanzhou/sjqiao",
	"/d/quanzhou/tudi",
	"/d/quanzhou/weiyuan",
	"/d/quanzhou/wangzhou",
	"/d/quanzhou/xuetang",
	"/d/quanzhou/yaofang",
	"/d/quanzhou/yaopu",
	"/d/quanzhou/yaopu_mishi",
	"/d/quanzhou/yongning",
	"/d/quanzhou/yuanhe",
	"/d/quanzhou/yuetai",
	"/d/quanzhou/zahuopu",
	"/d/quanzhou/zoulang1",
	"/d/quanzhou/zoulang2",
	"/d/quanzhou/caoan2",
	"/d/quanzhou/chengtian",
	"/d/quanzhou/chxiang",
	"/d/quanzhou/cien",
	"/d/quanzhou/citong_e1",
	"/d/quanzhou/citong_n1",
	"/d/quanzhou/citong_n2",
	"/d/quanzhou/citong_n3",
	"/d/quanzhou/citong_s1",
	"/d/quanzhou/citong_s2",
	"/d/quanzhou/duxiang",
	"/d/quanzhou/gangkou3",
	"/d/quanzhou/ganlu",
	"/d/quanzhou/gtxiang",
	"/d/quanzhou/houshan",
    "/d/beijing/kedian",
	"/d/beijing/beihai",
	"/d/beijing/caishikou",
	"/d/beijing/chaguan",
	"/d/beijing/chaoyangdajie",
	"/d/beijing/chaoyangmen",
	"/d/beijing/chongwendajie",
	"/d/beijing/chongwenmen",
	"/d/beijing/chouzhuang",
	"/d/beijing/dadao_yongan_s",
	"/d/beijing/dangpu",
	"/d/beijing/tianqiao",
	"/d/beijing/shizilukou",
	"/d/beijing/rank_info",
	"/d/beijing/quanjude",
	"/d/beijing/majiu",
	"/d/beijing/kedian2",
	"/d/beijing/huoshenmiao",
	"/d/beijing/guloudajie_e",
	"/d/beijing/guloudajie_w",
	"/d/beijing/dongzhidajie",
	"/d/beijing/dongzhimen",
	"/d/beijing/fuchengdajie",
	"/d/beijing/fuchengdajie_n",
	"/d/beijing/fuchengdajie_s",
	"/d/beijing/fuchengmen",
	"/d/beijing/gaoliangdi",
	"/d/beijing/guanganmen",
     });

string *yangguo = ({
    "金国","蒙古","契丹",
      });

string *menpai = ({
    "华山派","峨嵋派","武当派","少林派","丐帮",
    "白驼山","桃花岛","雪山派","星宿派",
    });

string ask_job();
string ask_finish();
string ask_abandon();

void create()
{
    set_name("杨过",({"yang guo","yang"}));
    set("long","神雕大侠\n");
    set("inquiry",([
        "job":(:ask_job:),
    "finish":(:ask_finish:),
    "完成":(:ask_finish:),
    "工作":(:ask_job:),
    "abandon":(:ask_abandon:),
      "放弃":(:ask_abandon:),
      ]));
    setup();
}

string ask_job()
{
     object me,ob,target;
    string msg;
    int i,level;
    int num;

    me=this_player();
    ob=this_object();
    level = pow(10*me->query("combat_exp"),0.333334);
    if(level<20) level = 20;
    i=0;
    i++;

    ob->set("count",10);

    if(me->query("family/family_name") != "古墓派")
        return "这话何从说起！\n";

    if(me->query("combat_exp")<200000)
        return "你武功差了点，还是去好好练功吧！\n";

    if(me->query("yang/job"))
        return "我交待你的任务完成了吗？\n";

    if(me->query_condition("yang_job"))
        return "你再去把功夫练练好，一会再来吧！\n";

    if(me->query_condition("yang_finish"))
          return "你先休息一会，暂时没什么事让你做！\n";

    if(!ob->query("count"))
        return "暂时没什么事让你做，你待会再来吧！\n";


    me->set("yang/job",1);
    ob->add("count",-1);
    target=new(__DIR__"target");
      target->set("combat_exp",me->query("combat_exp"));

//target 的武功设定
//target 的状况设定

    target->set_skill("force",level);
    target->set_skill("dodge",level);
    target->set_skill("parry",level);
    target->set_skill("sword",level);
    target->set_skill("blade",level);
    target->set_skill("strike",level);
    target->set_skill("cuff",level);
    target->set_skill("finger",level);
    target->set_skill("claw",level);
    target->set_skill("club",level);
    target->set_skill("staff",level);
    target->set_skill("whip",level);

    target->set("max_neili",level*12);
    target->set("neili",level*12);
    target->set("eff_jingli",level*10);
    target->set("max_jingli",level*10);
    target->set("jingli",level*10);
    target->set("max_qi",level*12);
    target->set("eff_qi",level*12);
    target->set("qi",level*12);
    target->set("max_jing",level*10);
    target->set("eff_jing",level*10);
    target->set("jing",level*10);
    target->set("jiali",level/10);


switch (menpai[random(sizeof(menpai))]){
case "华山派":
     target->set_skill("huashan-jianfa",level);
     target->set_skill("liangyi-dao",level);
    target->set_skill("huashan-shenfa",level);
    target->set_skill("zixia-gong",level);
    target->set_skill("pishi-poyu",level);
    target->set_skill("hunyuan-zhang",level);

    target->map_skill("force","zixia-gong");
    target->map_skill("dodge","huashan-shenfa");
    target->map_skill("parry","huashan-jianfa");
    target->map_skill("sword","huashan-jianfa");
    target->map_skill("strike","hunyuan-zhang");
    target->map_skill("cuff","pishi-poyu");
    target->map_skill("blade","liangyi-dao");

    target->prepare_skill("cuff","pishi-poyu");
    target->prepare_skill("strike","hunyuan-zhang");

    set("default_weapon","/clone/weapon/gangjian");
    break;

case "峨嵋派":
    target->set_skill("huifeng-jian",level);
    target->set_skill("yanxing-dao",level);
    target->set_skill("jinding-zhang",level);
    target->set_skill("tiangang-zhi",level);
    target->set_skill("linji-zhuang",level);
    target->set_skill("zhutian-bu",level);

    target->map_skill("force","linji-zhuang");
    target->map_skill("sword","huifeng-jian");
    target->map_skill("blade","yanxing-dao");
    target->map_skill("strike","jinding-zhang");
    target->map_skill("finger","tiangang-zhi");
    target->map_skill("dodge","zhutian-bu");
    target->map_skill("parry","huifeng-jian");

    target->prepare_skill("finger","tiangang-zhi");
    target->prepare_skill("strike","jinding-zhang");
    set("default_weapon","/clone/weapon/gangdao");
    break;

case "武当派":
    target->set_skill("taiji-shengong",level);
    target->set_skill("taiji-jian",level);
    target->set_skill("tiyunzong",level);
    target->set_skill("taiji-quan",level);

    target->map_skill("force","taiji-shengong");
    target->map_skill("parry","taiji-jian");
    target->map_skill("cuff","taiji-quan");
    target->map_skill("dodge","tiyunzong");
    target->map_skill("sword","taiji-jian");

    target->prepare_skill("cuff","taiji-quan");
    set("default_weapon","/clone/weapon/gangjian");
    break;

case "少林派":
    target->set_skill("damo-jian",level);
    target->set_skill("xiuluo-dao",level);
    target->set_skill("wuchang-zhang",level);
    target->set_skill("zui-gun",level);
    target->set_skill("shaolin-shenfa",level);
    target->set_skill("hunyuan-yiqi",level);
    target->set_skill("yizhi-chan",level);
    target->set_skill("banruo-zhang",level);

    target->map_skill("force","hunyuan-yiqi");
    target->map_skill("dodge","shaolin-shenfa");
    target->map_skill("parry","damo-jian");
    target->map_skill("sword","damo-jian");
    target->map_skill("blade","xiuluo-dao");
    target->map_skill("club","zui-gun");
    target->map_skill("staff","wuchang-zhang");
    target->map_skill("finger","yizhi-chan");
    target->map_skill("strike","banruo-zhang");

    target->prepare_skill("finger","yizhi-chan");
    target->prepare_skill("strike","banruo-zhang");
    set("default_weapon","/clone/weapon/gangjian");
    break;

case "丐帮":
    target->set_skill("liuhe-dao",level);
    target->set_skill("xiaoyaoyou",level);
    target->set_skill("huntian-qigong",level);
    target->set_skill("shexing-diaoshou",level);

    target->map_skill("force","huntian-qigong");
    target->map_skill("dodge","xiaoyaoyou");
    target->map_skill("parry","liuhe-dao");
    target->map_skill("blade","liuhe-dao");
    target->map_skill("hand","shexing-diaoshou");

    target->prepare_skill("hand","shexing-diaoshou");
    set("default_weapon","/clone/weapon/gangdao");
    break;

case "白驼山":
    target->set_skill("hamagong",level);
    target->set_skill("lingshe-zhang",level);
    target->set_skill("chanchubu",level);
    target->set_skill("poison",level);

    target->map_skill("force","hamagong");
    target->map_skill("dodge","chanchubu");
    target->map_skill("strike","hamagong");
    target->map_skill("parry","lingshe-zhang");
    target->map_skill("staff","lingshe-zhang");

    target->prepare_skill("strike","hamagong");
    set("default_weapon","/clone/weapon/shezhang");
    break;

case "桃花岛":
    target->set_skill("bitao-xuangong",level);
    target->set_skill("canglang-bian",level);
    target->set_skill("luoying-shenfa",level);
    target->set_skill("luoying-shenjian",level);
    target->set_skill("xuanfeng-saoye",level);
    target->set_skill("qimen-dunjia",level);

      target->map_skill("force","bitao-xuangong");
    target->map_skill("dodge","luoying-shenfa");
    target->map_skill("parry","canglang-bian");
    target->map_skill("strike","luoying-shenjian");
    target->map_skill("kick","xuanfeng-saoye");
    target->map_skill("whip","canglang-bian");

    target->prepare_skill("strike","luoying-shenjian");
    target->prepare_skill("kick","xuanfeng-saoye");
    set("default_weapon","/clone/weapon/changbian");
    break;

case "雪山派":
    target->set_skill("longxiang-banruo",level);
    target->set_skill("xue-dao",level);
    target->set_skill("jingang-chu",level);
    target->set_skill("huoyan-dao",level);
    target->set_skill("xueshitiao",level);
    target->set_skill("mingwang-jian",level);

    target->map_skill("force","longxiang-banruo");
    target->map_skill("dodge","xueshitiao");
    target->map_skill("parry","xue-dao");
    target->map_skill("blade","xue-dao");
    target->map_skill("sword","mingwang-jian");
    target->map_skill("strike","huoyan-dao");
    target->map_skill("staff","jingang-chu");

    target->prepare_skill("strike","huoyan-dao");
    set("default_weapon","/clone/weapon/gangdao");

    break;

case "星宿派":
    target->set_skill("huagong-dafa",level);
    target->set_skill("zhaixinggong",level);
    target->set_skill("chousui-zhang",level);
      target->set_skill("sanyin-zhua",level);
    target->set_skill("tianshan-zhang",level);
    target->set_skill("poison",level);

    target->map_skill("force","huagong-dafa");
    target->map_skill("strike","chousui-zhang");
    target->map_skill("claw","sanying-zhua");
    target->map_skill("dodge","zhaixinggong");
    target->map_skill("parry","sanyin-zhua");
    target->map_skill("staff","tianshan-zhang");

    target->prepare_skill("strike","chousui-zhang");
    target->prepare_skill("claw","sanyin-zhua");
    set("default_weapon","/clone/weapon/gangzhang");
    break;

    }


        num=random(sizeof(yangpath));
     target->move(yangpath[num]);
       msg="听说"+yangguo[random(sizeof(yangguo))]+"派了密探到了"+yangwhere[num]+"你去把他干了!\n";
    target->set("yang/name",me->query("id"));

    return msg;
}

string ask_finish()
{
    object me=this_player();
     int gain,pots;

      gain = 1000 + me->query("yang/finish")*30 + random(100);
    pots=100+random(150);

    if(!me->query("yang/finish") || me->query("family/family_name") != "古墓派")
        return "你完成了什么？\n";

    me->delete("yang/job");
    if ( me->query( "combat_exp" ) > 6400000 )
        gain = gain/2;
       me->add("combat_exp",gain);
    me->delete("yang/finish");
    me->delete("yang/ask");
     me->add("potential",pots);
    if(me->query("potential")>me->query("max_potential"))
    me->set("potential",me->query("max_potential"));
     me->apply_condition("yang_finish",10+random(4));

log_file("job/gumu_yang",me->query("name") + "(" + me->query("id") + ")做杨过工作获得" + gain + "点经验和" + pots +"点潜能" + ctime(time()) + "\n");

    return "做的很好，下去休息吧。\n";
}

string ask_abandon()
{
    object me=this_player();
    object ob=this_object();

    if(!me->query("yang/job"))
        return "你又没工作，放弃什么？\n";
    me->delete("yang/job");
       me->apply_condition("yang_job",15+random(10));
    message_vision("$N低声对$n说道：对不起，这个工作我没能完成！\n",me,ob);
 log_file("job/gumu_yang",me->query("name")+"("+me->query("id")+")做杨过工作放弃"+ctime(time())+"\n");
    return "知道了，你先下去吧";
}
