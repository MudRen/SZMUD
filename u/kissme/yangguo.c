inherit NPC;

string *yangwhere = ({
    "����","Ȫ��","����",
       });

string *yangpath = ({
    "/d/city/guangchang",
    "/d/quanzhou/zhongxin",
    "/d/beijing/kedian",
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
    set_name("���",({"yang guo","yang"}));
    set("long","������\n");
    set("inquiry",([
        "job":(:ask_job:),
    "finish":(:ask_finish:),
    "���":(:ask_finish:),
    "����":(:ask_job:),
    "abandon":(:ask_abandon:),
      "����":(:ask_abandon:),
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

    if(me->query("family/family_name") != "��Ĺ��")
        return "�⻰�δ�˵��\n";

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

      gain = 600 + me->query("yang/finish")*10 + random(100);
    pots=100+random(150);

    if(!me->query("yang/finish") || me->query("family/family_name") != "��Ĺ��")
        return "�������ʲô��\n";

    me->delete("yang/job");
       me->add("combat_exp",gain);
    me->delete("yang/finish");
    me->delete("yang/ask");
     me->add("potential",pots);
    if(me->query("potential")>me->query("max_potential"))
    me->set("potential",me->query("max_potential"));
     me->apply_condition("yang_finish",10+random(4));

log_file("job/gumu_yang",me->query("name") + "(" + me->query("id") + ")������������" + gain + "�㾭���" + pots +"��Ǳ��" + ctime(time()) + "\n");

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
 log_file("job/gumu_yang",me->query("name")+"("+me->query("id")+")�������������"+ctime(time())+"\n");
    return "֪���ˣ�������ȥ��";
}
