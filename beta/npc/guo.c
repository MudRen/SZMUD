#include <ansi.h>

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
        "泉州","泉州",
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
        set_name("郭靖", ({"guo jing", "guo", "jing"}));
        set("nickname", HIY"北侠"NOR);
        set("gender", "男性");
        set("age", 41);
        set("long", 
                "他就是人称北侠的郭靖，本是成吉思汗的金刀驸马，当蒙古入\n"
                "侵中原之时，毅然选择与襄阳城的百姓同生共死，达到了“侠\n"
                "之大者，为国为民”的境界，堪称为民族的脊梁。\n"
                "他身着一件灰色长袍，体态魁梧，敦厚的面目中透出一股威严\n"
                "令人不由得产生一股钦佩之情。\n");
        set("attitude", "peaceful");
        
        set("per", 20);
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 25);

   set("chat_chance", 1);
        set("chat_msg", ({
          "郭靖说道：“人生在世，便是做个贩夫走卒，只要有为国为民之心，那就是真好汉，真豪杰了。”\n",
          "郭靖说道：“只盼你心头牢牢记着『为国为民，侠之大者』这八个字，日后名扬天下，成为万民敬仰的大侠。”\n",
//              (: random_move :),
        }));

        set("inquiry", ([
                "周伯通" : "你见到我周大哥了？他现在可好？\n",
                "老顽童" : "周大哥心地很好，天真浪漫。\n",
                "洪七公" : "蓉儿说要给师父烧几样小菜，不过很久没有他老人家的消息了，我们很是挂念他。\n",
                "黄药师" : "那是我的岳父。我资质差的很，委屈了蓉儿了。蓉儿很想念父亲。\n",
                "一灯大师" : "在下对大师好生感激。\n",
                "欧阳锋" : "这个老毒物，害死我六位师父，一待襄阳事了，决不与他干休。\n",
                "黄蓉"   : "蓉儿是我的爱妻，你问她做甚？\n",
                "蓉儿"   : "蓉儿是我的爱妻，她这阵子身子不大好。\n",
                "郭芙"   : "芙儿自小任性刁蛮，惹下滔天大祸，我们好生对不起过儿。\n",
                "郭襄"   : "襄儿生于乱世，这辈子又多艰厄。但愿她今后能幸福安乐。\n",
                "郭破虏" : "那是我的小儿子。\n",
                "杨过"   : "过儿确实有出息。\n",
                "马钰"   : "马道长于我有半师之谊。\n",
                "丘处机" : "邱道长义薄云天，是真豪杰。\n",
                "柯镇恶" : "那是我大师父。\n",
                "朱聪"   : "那是我二师父。\n",
                "韩宝驹" : "那是我三师父。\n",
                "南希仁" : "那是我四师父。\n",
                "张阿生" : "那是我五师父。\n",
                "全金发" : "那是我六师父。\n",
                "韩小莹" : "那是我七师父。\n",
                "丐帮"   : "丐帮英雄几百年了，守卫襄阳多亏了他们。\n",
                "拜师"   : "现在蒙古人围攻襄阳，我哪有心情收徒啊！\n",
				"job"	 : (:ask_job:),
				"finish" : (:ask_finish:),
				"完成"	 : (:ask_finish:),
				"工作"	 : (:ask_job:),
				"abandon": (:ask_abandon:),
				"放弃"	 : (:ask_abandon:),
        ]));

        set("qi", 4000);
        set("max_qi", 4000);
        set("jing", 500);
        set("max_jing", 500);
        set("neili", 4000);
        set("max_neili", 4000);
        set("jiali", 100);
        
        set("combat_exp", 800000);
        set("score", 200000);
         
        set_skill("force", 150);                // 基本内功
        set_skill("huntian-qigong", 130);       // 混天气功
        set_skill("unarmed", 220);              // 基本拳脚
        set_skill("xianglong-zhang", 200);      // 降龙十八掌
        set_skill("dodge", 100);                // 基本躲闪
        set_skill("xiaoyaoyou", 80);            // 逍遥游
        set_skill("parry", 120);                // 基本招架
        
        map_skill("force", "huntian-qigong");
        map_skill("unarmed", "xianglong-zhang");
        map_skill("dodge", "xiaoyaoyou");
        map_skill("parry", "xianglong-zhang");
        
        setup();
        
        carry_object("/clone/misc/cloth")->wear();
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
    log_file( "yangpath", "\npath is "+yangpath[num] );
    target->move(yangpath[num]);
    log_file( "yangpath", ". Result -- OK " );
    msg="听说"+yangguo[random(sizeof(yangguo))]+"派了密探到了"+yangwhere[num]+"你去把他杀了!\n";
    target->set("yang/name",me->query("id"));

    return msg;
}

string ask_finish()
{
    object me=this_player();
	int gain,pots;

        gain = 1500 + me->query("yang/finish")*30 + random(100);
        pots=200+random(150);

///////////////////////add check by lisser //////////////////
        if (!me->query("yang/finish")){
                command("hmm "+me->query("id"));
                if (!me->query("yang/job")) return "没给你任务，你完成什么？";
                else return "你的任务还没有完成就想要奖励？"; 
        }
///////////////////////add check by lisser //////////////////

	me->delete("yang/job");
	me->add("combat_exp",gain);
	me->delete("yang/finish");
	me->delete("yang/ask");
	me->add("potential",pots);
	if(me->query("potential")>me->query("max_potential"))
		me->set("potential",me->query("max_potential"));
	me->apply_condition("yang_finish",10+random(4));

	log_file("job/guo_job",me->query("name") + "(" + me->query("id") + ")做郭靖工作获得" + gain + "点经验和" + pots +"点潜能" + ctime(time()) + "\n");

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
 log_file("job/guojing",me->query("name")+"("+me->query("id")+")做郭靖工作放弃"+ctime(time())+"\n");
    return "知道了，你先下去吧";
}
