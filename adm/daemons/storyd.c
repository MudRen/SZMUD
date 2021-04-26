// storyd.c

#include <ansi.h>

inherit F_DBASE;

private string *story_name = ({//ѡ�����
#if 1
        "laojun",
        "xiyou",
        "guanzhang",
        "nanji",
        "liandan",
	"caishen",
	"zhengxi",
	"zagang",
	"songdai",
	"niulang",
        "smashstory",
        "kargive",
        "neiligive",
        "task-mcyao",
        "pergive",
        "agegive",
        "xiyouji2",
        "smashstory",
        "neiligive",
        "task-mcyao",
        "agegive",
        "xiyouji2",
        "smashstory",
        "kargive",
        "neiligive",
        "task-mcyao",
        "pergive",
        "agegive",
        "xiyouji2",
        "smashstory",
        "neiligive",
        "task-mcyao",
        "agegive",
        "xiyouji2",
        "niulang",
        "niulang",
        "songdai",
        "songdai",
        "zagang",
        "zagang",
        "zhengxi",
        "zhengxi",
        "caishen",
        "caishen",
        "caishen",
        "zhengxi",
        "zagang",
        "songdai",
        "niulang",
        "xiyou",
        "xiyou",
        "xiyou",
#endif
        "normal",
});

private object  running_story;
private mapping history;
private int step;
int filter_listener(object ob);

void ready_to_start()
{
        remove_call_out("process_story");
        call_out("start_story", 64800 + random(64800));//���ʱ��
//        call_out("start_story", 1 + random(1));//���ʱ��
}
void go_on_process(object ob)
{
        remove_call_out("start_story");
        remove_call_out("process_story");
        call_out("process_story", 1, ob);
}

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "���¾���");
        CHANNEL_D->do_channel( this_object(), "alarm", "����ϵͳ�Ѿ�������\n");

        history = allocate_mapping(sizeof(story_name));
        ready_to_start();
}

int clean_up()
{
        return 1;
}

object query_running_story()
{
        return running_story;
}

void start_story()
{
        string name;
        object ob;
        int i;

        ready_to_start();
        CHANNEL_D->do_channel( this_object(), "alarm", "����ϵͳ��ʼѡ���¼���\n");

        for (i = 0; i < 12; i++)
        {
                name = story_name[random(sizeof(story_name))];
                if (undefinedp(history[name]))
                        history += ([ name : 0 ]);

                if (time() - history[name] > 14400 || name == "normal")
                {
                        history[name] = (int)time();
                        break;
                }
        }

        if (i >= 12) return;

        CHANNEL_D->do_channel( this_object(), "sys", "����ϵͳѡ�����¼�(" + name + ")��\n");

        name = STORY_DIR + name;
        if (ob = find_object(name))
                destruct(ob);

        catch(ob = load_object(name));
        running_story = ob;

        if (! objectp(ob))
                return;

        step = 0;
        go_on_process(ob);
}

void process_story(object ob)
{
        mixed line;
	object *listeners;
        string prompt;

        go_on_process(ob);

        if (! objectp(ob))
        {
                ready_to_start();
                return;
        }

        line = ob->query_story_message(step);
        step++;

        prompt = ob->prompt();
        if (! prompt) prompt = HIY "���������¡� " NOR;
        if (functionp(line)) catch(line = evaluate(line));
        if (stringp(line))
	{
		listeners = filter_array(users(), (: filter_listener :));
                message( "story",  prompt + WHT + line + "\n" NOR, listeners );
	}

        if (intp(line) && ! line)
        {
                ready_to_start();
                destruct(ob);
        }
}

int filter_listener(object ob)
{
	if (ob->query("env/no_story")) return 0;
	return 1;
}

void give_gift(string gift, int amount, string msg)
{
        int i;
        int num;

        object ob;
        string env;
        string *giftpath = ({
	"/d/city/guangchang",
        "/d/city/beidajie1",
        "/d/city/beidajie2",
        "/d/city/beijiao1",
        "/d/city/beijiao2",
        "/d/city/beijiao3",
        "/d/city/beijiao4",
        "/d/city/beimen",
        "/d/city/biaoju",
        "/d/city/bingyindamen",
        "/d/city/caizhu",
        "/d/city/chaguan",
        "/d/city/chaguan1",
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
        "/d/city/duchang",
        "/d/city/duchang2",
        "/d/city/eproom",
        "/d/city/ft_datang",
        "/d/city/furong",
        "/d/city/guopintan",
        "/d/city/houyuan",
        "/d/city/huadian",
        "/d/city/itembank",
        "/d/city/jiuguan",
        "/d/city/jiuguan2",
        "/d/city/jujinge",
        "/d/city/kantai",
        "/d/city/kedian",
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
        "/d/beijing/quanjude",
        "/d/beijing/majiu",
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
        "/d/changan/bingying",
        "/d/changan/bydamen",
	"/d/changan/byxiang",
	"/d/changan/center",
        "/d/changan/changankezhan",
        "/d/changan/chougou",
        "/d/changan/dadao",
        "/d/changan/datiepu",
        "/d/changan/dayanta",
        "/d/changan/dongmen",
        "/d/changan/dtt",
        "/d/changan/dufang",
        "/d/changan/eroad1",
        "/d/changan/eroad2",
        "/d/changan/eroad3",
        "/d/changan/gfdoor",
        "/d/changan/honghuage",
        "/d/changan/huadian",
        "/d/changan/jianyu",
        "/d/changan/jinyulou",
        "/d/changan/kezhan",
        "/d/changan/leitai",
        "/d/changan/luanfd",
        "/d/changan/luansg",
        "/d/changan/moshouju",
        "/d/changan/majiu",
        "/d/changan/nanmen",
        "/d/changan/nroad1",
        "/d/changan/nroad2",
        "/d/changan/nroad3",
        "/d/changan/qianyuan",
        "/d/changan/qianzhuang",
        "/d/changan/qlbfd",
        "/d/changan/roupu",
        "/d/changan/sroad1",
        "/d/changan/sroad3",
        "/d/changan/sroad2",
        "/d/changan/sroad6",
        "/d/changan/wgdayuan",
        "/d/changan/wroad3",
        "/d/changan/wroad2",
        "/d/changan/wroad1",
        "/d/changan/wroad4",
        "/d/changan/wuguan",
        "/d/changan/wwroad1",
        "/d/changan/wwroad4",
        "/d/changan/wwroad3",
        "/d/changan/wwroad2",
        "/d/changan/wwroad5",
        "/d/changan/wwroad6",
	"/d/changan/xfroad1",
        "/d/changan/xfroad4",
        "/d/changan/xfroad3",
        "/d/changan/xfroad2",
        "/d/changan/xfroad5",
        "/d/changan/xfroad6",
        "/d/changan/xiaolu",
        "/d/changan/ximen",
        "/d/changan/xiaoyanta",
        "/d/changan/xuyuanan",
        "/d/changan/yizhan",
	"/d/changan/zahuodian",
        "/d/changan/zhengting",
        "/d/kaifeng/dadao",
        "/d/kaifeng/daqiao",
        "/d/kaifeng/dongmen",
        "/d/kaifeng/eroad2",
        "/d/kaifeng/eroad1",
        "/d/kaifeng/duchuan",
        "/d/kaifeng/eroad2s",
        "/d/kaifeng/eroad2s",
        "/d/kaifeng/fumen",
        "/d/kaifeng/hhbian",
	"/d/kaifeng/guangchang",
        "/d/kaifeng/kaifengfu",
        "/d/kaifeng/kezhan",
        "/d/kaifeng/kezhan2",
        "/d/kaifeng/sroad1",
        "/d/kaifeng/nanmen",
        "/d/kaifeng/kezhan3",
        "/d/kaifeng/sroad2",
        "/d/kaifeng/sroad2e",
        "/d/kaifeng/sroad2w",
        "/d/kaifeng/tingyulou",
	"/d/kaifeng/tiandi2",
        "/d/kaifeng/tiandi1",
        "/d/kaifeng/wroad1",
        "/d/kaifeng/wroad2",
        "/d/kaifeng/wroad2s",
        "/d/kaifeng/ximen",
        "/d/kaifeng/xilin",
     });
     
    num=random(sizeof(giftpath));
    log_file( "giftpath", "\npath is "+giftpath[num] );
    env=(giftpath[num]);
    log_file( "giftpath", ". Result -- OK " );

                if (objectp(env))
                        tell_room(env, msg);
                for (i = 0; i < amount; i++)
                {
                        ob = new(gift);
                        ob->move(env);
                }
	        CHANNEL_D->do_channel( this_object(),
			"sys", sprintf(NOR WHT "��Ʒ%s" NOR WHT "������"
				HIC "%s" NOR WHT "(%O" NOR WHT ")��\n" NOR,
                               ob->name(), env->query("short"), env));
        }
