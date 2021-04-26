#include <ansi.h>

inherit NPC;

string *yangwhere = ({
    "����","����","����","����","����","����","����","����","����","����",
        "����","����","����","����","����","����","����","����","����","����",
        "����","����","����","����","����","����","����","����","����","����",
        "����","����","����","����","����","����","����","����","����","����",
        "����","����","����","����","����","����","����","����","����","����",
        "����","����","����","����","����","����","����","����","����","����",
        "����","����","����","����","����","����","����","����","����","����",
        "����","����","����","����","����","����","����","����","����","����",
        "����","����","����","����","����","����","����","����","����","����",
        "����","����","����","����","����","����","����","����","����",
        "Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��",
        "Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��",
        "Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��","Ȫ��",
        "Ȫ��","Ȫ��","Ȫ��","Ȫ��",
        "����","����","����","����","����","����","����","����","����","����",
        "����","����","����","����","����","����","����","����","����","����",
        "����","����","����","����","����","����","����","����",
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
    "���","�ɹ�","����",
      });

string *menpai = ({
    "��ɽ��","������","�䵱��","������","ؤ��",
    "����ɽ","�һ���","ѩɽ��","������",
    });

string ask_job();
string ask_finish();
string ask_abandon();


void create()
{
        set_name("����", ({"guo jing", "guo", "jing"}));
        set("nickname", HIY"����"NOR);
        set("gender", "����");
        set("age", 41);
        set("long", 
                "�������˳Ʊ����Ĺ����������ɹųɼ�˼���Ľ�����������\n"
                "�����߹֡�ȫ�������ڵ���������ؤ�����߹��͡�����ͯ����\n"
                "��ͨ���˵�ͽ�ܣ����������书��\n"
                "������һ����ɫ���ۣ���̬���࣬�غ����Ŀ��͸��һ������\n"
                "���˲��ɵò���һ������֮�顣\n");
        set("attitude", "peaceful");
        
        set("per", 20);
        set("str", 40);
        set("int", 20);
        set("con", 30);
        set("dex", 25);

        set("chat_chance", 1);
        set("chat_msg", ({
                "����̾�˿����������ɹű��ù��������£�һ�����ٳ���ƣ��ض��ֲ������ߣ���....\n",
                "����˵���������ݹ���������֪�ɺã����һ��Ҫ�ش�Įȥ��������\n",
//              (: random_move :),
        }));

        set("inquiry", ([
                "�ܲ�ͨ" : "��������ܴ���ˣ������ڿɺã�\n",
                "����ͯ" : "�ܴ��һ��������û��������\n",
                "���߹�" : "ʦ�����˳ԣ�����ϲ���档�����棬����Ϊ���ҳԵġ�\n",
                "��ҩʦ" : "������̩ɽ���ˡ��������ĺ����������ײ���β�ġ�\n",
                "һ�ƴ�ʦ" : "���¶Դ�ʦ�����м���\n",
                "ŷ����" : "����϶����������λʦ����һ���������ˣ������������ݡ�\n",
                "����"   : "�ض����ҵİ��ޣ�������������\n",
                "�ض�"   : "�ض������ض��ˡ�������ô����\n",
                "��ܽ"   : "���Ů�����ֱ��ֲ�������\n",
                "����"   : "��������������Ⱳ���ֶ��򡣵�Ը���ܿ���һ����\n",
                "����²" : "�����ҵ�С���ӡ�\n",
                "���"   : "����ȷʵ�г�Ϣ��\n",
                "����"   : "�����������а�ʦ֮�ꡣ\n",
                "�𴦻�" : "������屡���죬������ܡ�\n",
                "�����" : "�����Ҵ�ʦ����\n",
                "���"   : "�����Ҷ�ʦ����\n",
                "������" : "��������ʦ����\n",
                "��ϣ��" : "��������ʦ����\n",
                "�Ű���" : "��������ʦ����\n",
                "ȫ��" : "��������ʦ����\n",
                "��СӨ" : "��������ʦ����\n",
                "ؤ��"   : "ؤ��Ӣ�ۼ������ˣ�����������������ǡ�\n",
                "��ʦ"   : "�����ɹ���Χ��������������������ͽ����\n",
				"job"	 : (:ask_job:),
				"finish" : (:ask_finish:),
				"���"	 : (:ask_finish:),
				"����"	 : (:ask_job:),
				"abandon": (:ask_abandon:),
				"����"	 : (:ask_abandon:),
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
         
        set_skill("force", 150);                // �����ڹ�
        set_skill("huntian-qigong", 130);       // ��������
        set_skill("unarmed", 220);              // ����ȭ��
        set_skill("xianglong-zhang", 200);      // ����ʮ����
        set_skill("dodge", 100);                // ��������
        set_skill("xiaoyaoyou", 80);            // ��ң��
        set_skill("parry", 120);                // �����м�
        
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
        return "���书���˵㣬����ȥ�ú������ɣ�\n";

    if(me->query("yang/job"))
        return "�ҽ�����������������\n";

    if(me->query_condition("yang_job"))
        return "����ȥ�ѹ��������ã�һ�������ɣ�\n";

    if(me->query_condition("yang_finish"))
          return "������Ϣһ�ᣬ��ʱûʲô����������\n";

    if(!ob->query("count"))
        return "��ʱûʲô��������������������ɣ�\n";


    me->set("yang/job",1);
    ob->add("count",-1);
    target=new(__DIR__"target");
      target->set("combat_exp",me->query("combat_exp"));

//target ���书�趨
//target ��״���趨

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
case "��ɽ��":
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

case "������":
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

case "�䵱��":
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

case "������":
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

case "ؤ��":
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

case "����ɽ":
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

case "�һ���":
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

case "ѩɽ��":
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

case "������":
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
    msg="��˵"+yangguo[random(sizeof(yangguo))]+"������̽����"+yangwhere[num]+"��ȥ��������!\n";
    target->set("yang/name",me->query("id"));

    return msg;
}

string ask_finish()
{
    object me=this_player();
	int gain,pots;

	gain = 1000 + me->query("yang/finish")*30 + random(100);
	pots=100+random(150);

	if(!me->query("yang/finish") || me->query("family/family_name") != "��Ĺ��")
		return "�������ʲô��\n";

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

	log_file("job/guo_job",me->query("name") + "(" + me->query("id") + ")�������������" + gain + "�㾭���" + pots +"��Ǳ��" + ctime(time()) + "\n");

	return "���ĺܺã���ȥ��Ϣ�ɡ�\n";
}

string ask_abandon()
{
    object me=this_player();
    object ob=this_object();

    if(!me->query("yang/job"))
        return "����û����������ʲô��\n";
    me->delete("yang/job");
       me->apply_condition("yang_job",15+random(10));
    message_vision("$N������$n˵�����Բ������������û����ɣ�\n",me,ob);
 log_file("job/guojing",me->query("name")+"("+me->query("id")+")��������������"+ctime(time())+"\n");
    return "֪���ˣ�������ȥ��";
}