//fix by Cheap
//10-30-01
// sample master.c code
// xiake island master.c

inherit NPC;
inherit F_MASTER;

string ask_me();
string ask_job();
int auto_perform();
void assign_job(object ob);

string * npcs = ({
"穆易;扬州月老亭;mu yi",
"驿丞;扬州驿站;yi cheng",
"日本浪人;泉州;lang ren",
"林平之;扬州福威镖局;lin pingzhi",
"王老板;扬州天宝阁;wang laoban",
"曲三;杭州酒店;qu san",
"回回;泉州清净寺;huihui",
"庄允城;宜兴南浔镇;zhuang yuncheng",
"戚芳;三不管戚家大院;qi fang",
"许老板;泉州鸿翔绸缎庄;xu laoban",
"王通治;泉州济世堂老店;wang tongzhi",
"凤七;佛山英雄楼;feng qi",
"凤一鸣;佛山英雄会馆;feng yiming",
"刀客;杭州青石大道;dao ke",
"管家婆;长安房管处;room master",
"钱庄伙计;长安钱庄;huoji",
"小老板;长安杂货店;lao ban",
"英莲;扬州鲜花店;ying lian",
"单正;泰山岱宗坊;shan zheng",
"何红药;大理药铺;he hongyao",
"马五德;泉州武馆正厅;ma wude",
"歌女;大理城太和居二楼;ge nu",
"清法比丘;少林广场;qingfa biqiu",
"灵虚道长;武当玄岳门;lingxu daozhang",
"葛伦布;雪山大轮寺;ge lunbu",
"丁春秋;星宿日月洞;ding chunqiu",
"欧阳克;扬州城西小山丘;ouyang ke",
"陆乘风;归云庄书房;lu chengfeng",
"高根明;华山玉女峰山路;gao genming",
"班淑娴;昆仑三圣堂;ban shuxian",
"丘处机;重阳宫长春殿;qiu chuji",
"皮清玄;重阳宫大门;pi qingxuan",
"李明霞;峨嵋华严顶;li mingxia",
"贝锦仪;峨嵋睹光台;bei jinyi",
"李莫愁;嘉兴南湖;li mochou",
"小龙女;古墓後堂;xiao longer",
"段陉;大理城法堂;duan jin",
"八旗子弟;北京正阳门;baqi zidi",
"一言堂伙计;北京一言堂;huoji",
"胡老爷;巴依家院;hu laoye"
});

void create()
{
    set_name("鲁有脚", ({"lu youjiao", "lu", "youjiao"}));
    set("title", "丐帮九袋长老");
    set("nickname", "掌棒龙头");
    set("gender", "男性");
    set("age", 45);
    set("long",
        "鲁有脚虽然武功算不得顶尖高手，可是在江湖上却颇有声望。\n"
        "因为他在丐帮中有仁有义，行事光明磊落，深得洪七公的器重。\n");
    set("attitude", "peaceful");
    set("str", 25);
    set("int", 12);
    set("con", 25);
    set("dex", 20);

    set("rank", 9);

    set("qi", 1200);
    set("max_qi", 1200);
    set("jing", 1000);
    set("max_jing", 1000);
    set("neili", 1500);
    set("max_neili", 1500);
    set("jiali", 150);

    set("combat_exp", 750000);
    set("score", 20000);

    set_skill("force", 140); // 基本内功
    set_skill("huntian-qigong", 140); // 混天气功
    set_skill("strike", 150); // 基本拳脚
    set_skill("xianglong-zhang", 150); // 降龙十八掌
    set_skill("dodge", 130); // 基本躲闪
    set_skill("xiaoyaoyou", 130); // 逍遥游
    set_skill("parry", 150); // 基本招架
    set_skill("stick", 150); // 基本棍杖
    set_skill("dagou-bang", 150);
    set_skill("begging", 130);
    set_skill("training", 100);

    map_skill("force", "huntian-qigong");
    map_skill("strike", "xianglong-zhang");
    map_skill("stick", "dagou-bang");
    map_skill("dodge", "xiaoyaoyou");

    prepare_skill("strike", "xianglong-zhang");

    create_family("丐帮", 18, "九袋长老");

    set("inquiry", ([
        "棒法图解" : (: ask_me :),
        "图解" : (: ask_me :),
        "密籍" : (: ask_me :),
        "密笈" : (: ask_me :),
        "帮务" : (: ask_job :),
        "job" : (: ask_job :),
    ]));

    set("book_count", 1);

    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: auto_perform :),
    }) );

    setup();

    carry_object("/d/gaibang/obj/budai")->set_amount(8);
    carry_object("/d/gaibang/obj/budai")->wear();
    carry_object("/clone/weapon/zhubang")->wield();
}

void init()
{
    object ob;

    ::init();

    set_heart_beat(1);

    if ( interactive( ob = this_player() )
    && ob->query("family/family_name") == "丐帮"
    && ob->query("gb/job_pending") ) {
        remove_call_out("check_job");
        call_out("check_job", 1, ob);
    }
}

void attempt_apprentice(object ob)
{
    if (ob->query("class")=="bonze") {
        if (ob->query("gender")=="女性")
            command ("say 师太是是出家人，怎么能在本帮做叫化子呢？");
        return;
    }

    if ( (int)ob->query("int") >= 25 ) {
        command("say 我们丐帮的武艺一向以刚猛为主，" +
        RANK_D->query_respect(ob) + "聪慧过人，似乎不宜学丐帮的功夫？");
        return;
    }

    if( ob->query("family/family_name") != "丐帮" )
    {
        if( ob->query("rank") > 1 ) {
            command("say 本帮以忠义为先，可容不下你这种无信无义的家伙！\n");
            return;
        }

        command("say 好吧，希望" + RANK_D->query_respect(ob) +
        "能好好学习本门武功，将来在江湖中闯出一番作为。");
        ob->set("rank", 1);
        command("recruit " + ob->query("id"));
        ob->set("title;丐帮一袋弟子");
    }
    else
    {
        ob->set_temp("title", ob->query("title"));
        command("recruit " + ob->query("id"));
        ob->set("title", ob->query_temp("title"));
        ob->delete_temp("title");
    }
}

string ask_me()
{
    mapping fam;
    object ob, me=this_object();

    if (!(fam = this_player()->query("family")) || fam["family_name"] != "丐帮")
        return RANK_D->query_respect(this_player())+"与本帮毫无渊源，怎么能开口向我要棒法图解？";

       if ((fam = this_player()->query("family")) || fam["family_name"] = "丐帮")
        return RANK_D->query_respect(this_player())+"请你去问彭有敬";

}

int accept_object(object me, object obj)
{

    object ob = this_player();

    if ( (obj->name() == "牛皮酒袋" || obj->name() == "花雕酒袋")
    && obj->query("liquid/type") == "alcohol" ) {
        call_out("drink_jiudai", 1, this_object(), ob, obj);
        return 1;
    }

    command( "say 这东西老叫化我不感兴趣，还是你自个儿留着吧。" );
    return 0;
}

int drink_jiudai(object me, object ob, object obj)
{
    if ( obj->query("liquid/remaining") >= 5 ) {
        message_vision("鲁有脚拿起酒袋一仰头，将整袋酒咕嘟咕嘟地一饮而尽。\n", me);
        command( "taste" );
        if ( ob->query("family/family_name") == "丐帮" ) {
            command( "nod" );
            command( "say 好！有什么问题你问吧。" );
            ob->set_temp("lu", 1);
        }
        else {
            command( "say 多谢这位"+RANK_D->query_respect(ob)+"。这酒真不坏。\n" );
            command( "smile" );
        }
    }
    else if ( obj->query("liquid/remaining") == 0 ) {
        message_vision("鲁有脚大怒说道：你当老子傻的啊？拿个空酒袋来消遣老子？\n", me);
        if ( ob->query("family/family_name") == "丐帮" ) {
            command( "slap " + obj->query("id") );
            ob->set_temp("lu", 2);
        }
    }
    else {
        command( "say 嘿嘿，才这么点酒就想我指点你？太美了吧！");
    }

    remove_call_out("destroy_it");
    call_out("destroy_it", 1, obj);
    return 1;
}

void destroy_it(object obj)
{
    destruct(obj);
}

void assign_job(object ob)
{
    object obj, *target_list;
    int i;
    string str, clan, place;
    string *npc;
    i = random( sizeof ( npcs ) );
    str = npcs[ i ];
    npc = explode( str, ";" );

    message_vision("鲁有脚伸手入怀取出一封信笺。\n", ob);
    message_vision("鲁有脚对$N说道：你把这封密函交给"+npc[1]+npc[0]+"，务必亲自送到！\n", ob);
    obj=new("/d/gaibang/obj/mihan");
    if ( npc[1] != "" ) clan = "【"+npc[1]+"】";
    else clan = "";
    obj->set("long","密函上面写着："+clan+""+npc[0]+"亲启。\n");
    obj->set("target_id", npc[2]);
    obj->set("target_name", npc[0]);
    obj->set("owner", ob->query("id"));
    obj->move(ob);
    //log_file("job/gaibang",ob->query("name")+" (" +
    //    ob->query("id") + ") 领取密函任务  "+ctime(time())+"\n");

}


string ask_job()
{
    object ob = this_player();
    object me = this_object();

    if ( ob->query("gb/job_status") == 2 ) {
        remove_call_out("check_job");
        call_out("check_job", 1, ob);
        return "噢！你那麽快便回来啦？\n";
    }
    else if ( ob->query("gb/job_pending") && ob->query_condition("gb_job") > 0 )
        return "你还没完成我交待的工作，怎麽又来问我？\n";
    else if ( ob->query("gb/job_pending") && !ob->query_condition("gb_job") ) {
//remove_call_out("check_job");
        call_out("check_job", 1, ob);
        return "噢！你回来啦？\n";
    }

     if ( ob->query("family/family_name") != "丐帮" && ob->query("combat_exp") > 200000 )
         return RANK_D->query_respect(ob)+"非我丐帮兄弟，又已经是别派的高手，不敢让您劳烦。\n";
    if ( time() < ob->query( "mp_job_time" ) + 180 )
        return "我现在没要事让你去干，待会儿你再来吧。\n";
    command("nod");
    ob->set( "mp_job_time", time() );
    call_out("assign_job", 1, ob);
    ob->set("gb/job_pending", 1);
    //ob->apply_condition("gb_job", 3+random(3));
    ob->set("gb/job_status", 1);
    return "你来得正巧，我有件事要你去办！\n";
}

int check_job(object ob)
{
    object me=this_object();
    int expG, potG;
    if ( ob->query("gb/job_status") == 2 )
    {
        ob->delete("gb/job_pending");
        ob->delete("gb/job_status");
        ob->add("gb/job_comp", 1);
        expG = 180+random(40);
        ob->add("combat_exp", expG );
        ob->add("potential", expG*2/5 );
        if ( ob->query("potential") > ob->query("max_potential") )
            ob->set("potential", ob->query("max_potential"));
        command("nod");
        message_vision("鲁有脚对$N道：很好！你完成了任务，下去休息吧。\n", ob);
    }
    else if ( ob->query("gb/job_status") == 1 && !ob->query_condition("gb_job")
    && present("mihan", ob) ) {
        ob->apply_condition("gb_job", 3);
        message_vision("鲁有脚气得对$N大吼：你还待在这里偷懒？还不快给我把密函送去！\n", ob);
    }
    else if ( ob->query("gb/job_pending") && !ob->query_condition("gb_job") ) {
        ob->apply_condition("gb_job", 3);
        ob->set("gb/job_fail", 1);
        ob->delete("gb/job_pending");
        ob->delete("gb/job_status");
        message_vision("鲁有脚气得对$N大吼：你这没用的家伙！怎麽把密函给弄丢了？快给我滚开！\n", ob);
    }

    return 1;
}

int auto_perform()
{
    object me=this_object();
    object weapon=me->query_temp("weapon");
    object opp=me->select_opponent();

    if ( !me->is_fighting() ) {
        if ( me->query("eff_qi") < me->query("max_qi") )
            exert_function("heal");
        me->set("jiali", 50);

        return 1;
    }

    if ( !me->query_temp("powerup") ) {
        return exert_function("powerup");
    }

    if ( objectp(weapon) ) {
        if ( !me->query_temp("shengang") )
            return exert_function("shengang");

        if ( weapon->query("skill_type") == "stick" )
            return perform_action("stick.chan");
    }
    else {
            return perform_action("strike.leiting");
    }
}
