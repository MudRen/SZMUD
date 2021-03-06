// by jiuer
// npcloc.c NPC 位置图

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("神州人物谱", ({ "tu", "map", "npc map"}));
        set_color(GRN);
		set_weight(40);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "张");
                set("long", "这是一张神州NPC地点分布图，是丐帮弟子多年送信后记录下来的
数据。你可以用丐帮暗语(npc)来查看NPC所在的各个地区。\n
比如：npc yz，npc wud等。\n
----------------------------------------------------------------------
少林: sl      武当: wud     全真: qz     星宿: xx     丐帮: gb     
白驼: bt      华山: hs      雪山: xs     峨嵋: emei   大理: dali    
西夏: xi      长乐帮: clb   扬州: yz     泉州: qzh    佛山: foshan
杭州: hz      嘉兴: jiax    古墓: gm
----------------------------------------------------------------------
	 \n");
        
        set("value", 200);
		set("no_steal",1);
		set("material", "paper");
		}
setup();
}

void init()
{
	add_action("do_npc","npc");
}

int do_npc(string arg)
{
	object me = this_player();

	if( !arg || arg == "")	return 0;

	else if( arg == "yz" || arg == "扬州")
	{
     write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                        『扬州NPC方位图』　　　　　　　　　　　　　   　┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃扬州城　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃东南西北门 - 武将(Wu jiang) 官兵(Guan bing) 衙门 - 衙役(Ya yi)　　　　　┃
┃衙门正厅 - 水陆提督 李克秀(Li kexiu) 师爷「绵里针」陆高止(Lu gaozhi)　  ┃
┃驿站 - 驿丞(Yi cheng)　　　　　　　　　　　                             ┃
┃兵营 - 扬州守将 赵良栋(Zhao liangdong)                                  ┃
┃福威镖局 - 镖头(Biao tou) 林平之(Lin pingzhi) 林震南(Lin zhennan)       ┃
┃翰林府院 - 管家(Guan jia) 家丁(Jia ding)                                ┃
┃后院 - 翰林 凌退思(Ling tuisi)丫鬟卧房 - 丫鬟 菊友(Juyou)               ┃
┃月老亭 - 民女 小姗(Shan)  看台 - 穆易(Mu yi)                            ┃",me);
write ("
┃钱庄 - 华山派弟子「铜笔铁算盘」黄真(Huang zhen)                         ┃
┃药铺 - 药铺老板「杀人神医」平一指(Ping yizhi) 药铺伙计(Yaopu huoji)     ┃
┃打铁铺 - 工匠(Gong jiang) 王铁匠(Wang tiejiang)                         ┃
┃杂货铺 - 杂货铺老板 杨永福(Yang yongfu)                                 ┃
┃书院 - 朱熹(Zhu xi)  马厩 - 马夫(Ma fu)                                 ┃
┃天宝阁 - 王老板(Wang laobang) 神龙教第二代教众 胖头陀(Pang toutuo)      ┃
┃客店 - 店小二(Xiao er)　醉仙楼 - 店小二(Xiao er)　　　　　　　　　　　　┃
┃醉仙楼二楼 - 醉仙楼老板 冼老板(Xian laoban) 酒客 王五(Wang wu)          ┃
┃当铺 - 当铺老板 唐楠(Tang nan)                                          ┃
┃赌场 - 神龙教第二代教众 瘦头陀(Shou toutuo)                             ┃
┃聚金阁 - 聚金阁掌柜 牛掌柜(Niu zhanggui) 聚金阁伙计(Huoji)              ┃
┃果品摊 - 相士(Xiang shi) 小贩(Xiao fan)  东南街 - 女孩(Girl)            ┃
┃米铺 - 长乐帮伙计(Huoji) 长乐帮长信堂香主 米横野(Mi hengye)             ┃",me);
write("
┃小土路 - 男孩(Boy)   民屋 - 女孩(Girl) 少妇(Young woman)                ┃
┃大堂 - 斧头帮帮主 程金斧(Cheng jinfu)                                   ┃
┃街边酒馆 - 酒馆老板 杜老板(Du laoban) 张十五(Zhang shiwu)               ┃
┃南大街 - 少林弟子 托钵僧(Tuobo seng)                                    ┃
┃丽春院 - 老板娘 韦春芳(Wei chunfang) 龟奴(Guinu) 空空儿(Kong kong)      ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃扬州西北  　　　　　　　　　                                            ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃树林 - 太岳四侠「流星赶月」花剑影(Hua jianying)                         ┃
┃       太岳四侠「踏雪无痕、独脚水上飞」盖一鸣(Gai yiming)               ┃
┃       太岳四侠「烟霞神龙」逍遥子(Xiaoyao zi)                           ┃
┃       太岳四侠「双掌开碑」常长风(Chang changfeng)                      ┃
┃黄河岸边 - 「三头蛟」侯通海(Hou tonghai)                                ┃",me);
write("
┃           黄河四鬼老大「断魂刀」沈青刚(Shen qinggang)                  ┃
┃           黄河四鬼老三「夺魄鞭」马青雄(Ma qingxiong)                   ┃
┃           黄河四鬼老二「追命枪」吴青烈(Wu qinglie)                     ┃
┃           黄河四鬼老四「丧门斧」钱青健(Qian qingjian)                  ┃
┃           黄河帮帮主「鬼门龙王」沙通天(Sha tongtian)                   ┃
┃           「千手人屠」彭连虎(Peng lianhu)                              ┃
┃           「参仙老怪」梁子翁(Liang ziweng)                             ┃
┃           「铁面判官」单正(Shan zheng)     慕容博(Murong bo)           ┃
┃            黄河岸边 - 「滑不留手」游迅(You xun)   祖千秋(zu qianqiu)   ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃扬州萧府                                                                ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃萧府大门 - 佣妇 张妈(Zhang ma)                                          ┃",me);
write("
┃大厅 - 「晋阳大侠」萧半和(Xiao banhe)                                   ┃
┃花园 - 任飞燕(Ren feiyan)        林玉龙(Lin yulong)                     ┃
┃闺房 - 书生 袁冠男(Yuan guannan) 萧中慧(Xiao zhonghui)                  ┃
┃石洞 - 黑风双煞「铁尸」梅超风(Mei chaofeng)「铜尸」陈玄风(Chen xuanfeng)┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
     return 1;
	}

	else if(arg == "xs" || arg == "雪山")
	{
		write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                          『大雪山NPC方位图』　　　　                   ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃山路 - 「柔云剑」刘承风(Liu chengfeng)                                  ┃
┃       「仁义陆大刀」陆天抒(Lu tianshu)                                 ┃
┃       「冷月剑」水岱(Shui dai)                                         ┃   
┃       「中平无敌」花铁干(Hua tiegan)                                   ┃
┃石峡谷 - 血刀门第五代弟子 善勇(Shanyong)                                ┃
┃山门 --- 葛伦布(Ge lunbu)                                               ┃
┃大广场 - 雪山派第十二代弟子 昌齐大喇嘛(Changqi lama)                    ┃
┃度母殿 - 值日喇嘛(Zhiri lama)  长廊 - 戒律僧(Jielv seng)                ┃
┃大殿 --- 值日喇嘛(Zhiri lama)  厨房 - 小喇嘛(Xiao lama)                 ┃
┃金刚院 - 雪山派第十一代喇嘛 萨木活佛(Samu huofo)                        ┃",me);
write("
┃时伦院 - 雪山派第十代喇嘛 灵智上人(Lingzhi shangren)                    ┃
┃拉章别院 - 大轮寺喇嘛 拉章活佛(Lazhang huofo)                           ┃
┃昂欠一楼 - 嘉木活佛(Jiamu huofo)                                        ┃
┃昂欠二楼 - 雪山派第六代掌门人「大轮明王」鸠摩智(Jiumozhi)               ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃大雪山山谷 - 采药人(Caiyao ren)    血刀门第五代弟子 胜谛(Shengdi)       ┃
┃洞口 - 血刀门第五代弟子 宝象(Bao xiang)   小喇嘛(Xiao lama)             ┃
┃洞口 -  血刀门第四代掌门人 血刀老祖(Xuedao laozu)                       ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
        return 1;
	}

	else if(arg =="qz" || arg =="全真")
	{ write("										
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                          『全真教NPC方位图』                           ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃普光寺 - 全真教第四代弟子 鹿清笃(Lu qingjia)  申志凡(Shen zhifan)       ┃
┃抱子岩 - 全真教第三代弟子 陈志益(Chen zhiyi)                            ┃
┃大校场 - 全真教第三代弟子 尹志平(Yin zhiping)                           ┃
┃         全真教第三代弟子 李志常(Li zhichang)                           ┃
┃         全真教第三代弟子 陈志益(Chen zhiyi)                            ┃
┃         全真教第三代弟子 崔志方(Cui zhifang)                           ┃
┃         全真教第三代弟子 申志凡(Shen zhifan)                           ┃
┃         全真教第三代弟子 赵志敬(Zhao zhijing)                          ┃
┃重阳宫大门  全真教第四代弟子 皮清玄(Pi qingxuan)                        ┃",me);
write("
┃接引殿 - 全真教第三代弟子「清和真人」尹志平(Yin zhiping)                ┃
┃三清殿 - 全真教第二代弟子「玉阳子」王处一(Wang chuyi)                   ┃
┃广宁殿 - 全真教第二代弟子「广宁子」郝大通(Hao datong)                   ┃
┃东厢走廊 - 全真教第三代弟子 房志起(Fang zhiqi)                          ┃
┃西厢走廊 - 全真教第三代弟子 王志谨(Wang zhijin)                         ┃
┃重阳宫广场 - 全真教第四代弟子 姬清虚(Ji qingxu)                         ┃
┃阳宫长春殿 - 全真教第二代弟子、掌教真人「长春子」丘处机(Qiu chuji)      ┃
┃长生殿 - 全真教第二代弟子「长生子」刘处玄(Liu chuxuan)                  ┃
┃重阳宫後殿 - 全真教第二代弟子「丹阳子」马钰(Ma yu)                      ┃
┃台阶 - 全真教第三代弟子 张志光(Zhang zhiguang)                          ┃
┃养心殿 - 全真教第二代弟子「清静散人」孙不二(Sun buer)                   ┃
┃藏经阁 - 全真教第三代弟子 李志常(Li zhichang)                           ┃
┃藏经阁二楼 - 全真教第二代弟子「长真子」谭处端(Tan chuduan)              ┃",me);
write("
┃静室 - 全真教第三代弟子 程瑶迦(Cheng yaojia)                            ┃
┃玉虚洞 - 全真教第三代弟子 王志坦(Wang zhidan)                           ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
	return 1;
	}

	else if( arg =="dali" || arg == "大理")
	{ write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                            『大理NPC方位图』                           ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃下关城 - 乌夷商贩(Shang fan) 台夷商贩(Shang fan)  官道 - 摆夷女子(Girl) ┃
┃剑川镇 - 猎人(Lie ren) 皮货商(Pihuo shang)                              ┃
┃村外草坡 - 牧羊女(Muyang nu) 牧羊人(Muyang ren)                         ┃
┃祭祀大屋 - 乌夷老祭司(Lao jisi)                                         ┃
┃王府大门 - 大理国武将 褚万里(Zhu wanli) 锦衣卫士(Wei shi)               ┃
┃黄衣卫士(Wei shi)  小厮子(Xiao si)    甬路 - 小丫鬟(Ya huan)            ┃
┃前院 - 平南王府管家「金算盘」崔百泉(Cui baiquan)                        ┃
┃府衙前厅 - 副将(Fu jiang) 黄衣卫士(Wei shi)     士兵(Shi bing)          ┃
┃司空堂 - 大理国司空 巴天石(Ba tianshi) 大理国司徒 华赫艮(Hua hegen)     ┃
┃司马堂 - 大理国司马 范骅(Fan ye)  护院武士领队(Weishi lingdui)          ┃",me);
write("
┃护院武士(Wei shi) 厢房 - 卫士长(Weishi zhang)  茶花院 - 花匠(Hua jiang) ┃
┃理国武将 朱丹臣(Zhu danchen)                                            ┃
┃书房 - 大理第十五代文安皇帝 段正淳(Duan zhengchun)                      ┃
┃定安府 - 大理国武将 傅思归(Fu sigui) 副将(Fu jiang)                     ┃
┃法堂 - 大理国武将 总管(Zong guan) 摆夷判官(Pan guan) 段陉(Duan jin)     ┃
┃小院 - 护院武士(Wei shi) 小厮子(Xiao si)                                ┃
┃蛇骨塔 - 小孩(Kid) 石铺 - 石匠(Shi jiang) 薛记成衣铺 薛老板(Xue laoban) ┃
┃药铺 - 五毒教堂主 何红药(He hongyao)    江湖艺人(Jianghu yiren)         ┃
┃太和居二楼 - 太和居老板 宋老板(Song laoban) 歌女(Ge nu)                 ┃
┃土司府 - 侍从(Shi cong) 大土司(Da tusi) 议事厅 - 族头人(Zu touren)      ┃
┃兵营 - 黄衣卫士(Wei shi) 士兵(Shi bing)                                 ┃
┃摆夷民居 - 摆夷老叟(Oldman) 南国姑娘(Girl)                              ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫",me);
write("
┃古道                                                                    ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃大厅 - 侍者(Shi zhe)   客房 - 陪从(Pei cong)	                          ┃ 
┃楼梯 - 善阐侯 高升泰(Gao shengtai) 素衣卫士(Wei shi)                    ┃
┃贵宾房 - 洪源洞洞主 傣族首领(Daizu shouling)                            ┃
┃山路 - 无量剑弟子(Wuliang dizi) 山路 - 神农帮弟子(Shennong dizi)        ┃
┃喜州城 - 盛皮罗客商(Ke shang)   榕树雨林 - 台夷猎人(Lie ren)            ┃
┃武定镇 - 台夷姑娘(Gu niang)  青竹林 - 采笋人(Caisun ren)                ┃
┃农田 - 台夷农妇(Nong fu)   鲁望镇 - 台夷商贩(Shang fan)                 ┃
┃议事堂 - 族长(Zu zhang)    祭祀屋 - 祭司(Ji si)                         ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
return 1;
	}
	else if(arg == "emei" || arg == "娥媚")
	{
		write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『娥媚NPC方位图』                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃青石阶 - 仆人(Pu ren) 年轻少妇(Young woman)                             ┃
┃草棚 - 小贩(Xiao fan)                                                   ┃
┃马厩 - 马夫(Ma fu)                                                      ┃
┃报国寺山门 - 进香客(Jingxiang ke)                                       ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃藏经楼 - 峨嵋派第五代弟子 道明小师父(Daoming)                           ┃
┃伏虎寺 - 峨嵋派第五代弟子 女弟子(Dizi)  男弟子(Dizi)                    ┃ 
┃玉女峰 - 峨嵋派第四代弟子 方碧琳(Fang bilin)                            ┃
┃福寿庵 - 峨嵋派第四代弟子 静真师太(Jingzhen shitai)                     ┃
┃灵文阁 - 峨嵋派第四代弟子 静照师太(Jingzhao shitai)                     ┃",me);
write("
┃清音阁 - 峨嵋派第四代弟子 静闲师太(Jingxian shitai)                     ┃
┃华严顶 - 峨嵋派第四代弟子 李明霞(Li mingxia)                            ┃
┃莲花石 - 峨嵋派第四代弟子 苏梦清(Su mengqing)                           ┃
┃         峨嵋派第四代弟子 赵灵珠(Zhao lingzhu)                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃千佛庵大殿 - 峨嵋派第五代弟子 文音小师太(Wenyin)                        ┃
┃           - 静慧师太(Jinghui shitai)                                   ┃
┃万行庵 - 峨嵋派第四代弟子 静迦师太(Jingjia shitai)                      ┃
┃睹光台 - 峨嵋派第四代弟子 贝锦仪(Bei jinyi)                             ┃
┃卧云庵 - 峨嵋派第四代弟子 静玄师太(Jingxuan shitai)                     ┃
┃华藏庵正殿 - 峨嵋派第四代弟子 静心师太(Jingxin shitai)                  ┃
┃华藏庵侧殿 - 峨嵋派第五代弟子 文清小师太(Wenqing)                       ┃
┃华藏庵侧殿 - 峨嵋派第五代弟子 文晖小师太(Wenhui)                        ┃",me);
write("
┃             峨嵋派第四代弟子 静和师太(Jinghe shitai)                   ┃
┃华藏庵广场 - 峨嵋派第四代弟子 静虚师太(Jingxu shitai)                   ┃
┃储物间 - 峨嵋派第四代弟子 静风师太(Jingfeng shitai)                     ┃
┃华藏庵后殿 - 峨嵋派第三代掌门人 灭绝师太(Miejue shitai)                 ┃
┃                                                                        ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
      return 1;
	}

	else if(arg =="clb" || arg =="长乐帮")
	{
		write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『长乐帮NPC方位图』                        ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃小厅 - 「八爪金龙」司徒横(Situ heng)                                    ┃
┃卧室 - 侍剑(Shijian)                                                    ┃
┃甬道 - 长乐帮虎猛堂 帮众(Changle bangzhong)                             ┃
┃石室 - 长乐帮豹捷堂香主 展飞(Zhan fei)                                  ┃
┃小屋 - 长乐帮豹捷堂 帮众(Changle bangzhong)                             ┃
┃大厅 - 「着手成春」贝海石(Bei haishi)                                   ┃
┃大门 - 长乐帮虎猛堂香主 邱山风(Qiu shanfeng)                            ┃
┃八角亭 - 「叮叮当当」丁当(Ding dang)                                    ┃
┃树林 - 快刀门掌门人 吕正平(Lu zhengping)                                ┃
┃       鹤笔门掌门人 范一飞(Fan yifei)                                   ┃",me);
write("
┃       万马庄女庄主 高三娘子(Gao san)                                   ┃
┃       青龙门掌门人 风良(Feng liang)                                    ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
return 1;
	}

	else if(arg == "qzh" || arg == "泉州")
	{ 
		write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『泉州地区NPC方位图』                      ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃港口路 - 镖头(Biao tou)        日本浪人(Lang ren)                       ┃
┃万国烟雨楼 - 店小二(Xiao er)   万国烟雨楼老板 吴老板(Wu laoban)         ┃
┃鸿翔绸缎庄 - 鸿翔绸缎庄老板 许老板(Xu laoban)   伙计(Huoji)             ┃
┃土地庙 - 地痞(Dipi) 小流氓(Punk)                                        ┃
┃后渚港 - 水师士兵(Shuishi bing)                                         ┃
┃淘然茶居 - 淘然茶居老板 陶老人(Tao lao)                                 ┃
┃打铁铺 - 铁匠(Tie jiang)                                                ┃
┃乱石岗 - 土匪(Tufei) 土匪头(Tufei tou)                                  ┃
┃清净寺 - 回回(Huihui)                                                   ┃
┃阿拉伯宅区 - 阿拉伯商人(Alabo shangren)                                 ┃",me);
write("
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃泉州武馆                                                                ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃武馆大门 - 武馆门丁(Men ding)              考教场 - 武馆学徒(Xue tu)    ┃
┃前厅 - 马五德(Ma wude)                                                  ┃
┃       刀刃部 - 「一刀平南」龙铨(Long quan)                             ┃
┃       棒杖部 - 「狂虎」陈浒(Chen hu)                                   ┃
┃       剑部 - 「绝情剑」刘虹瑛(Liu hongying)                            ┃
┃       暗器部 - 「漫天花雨」萧飞(Xiao fei)                              ┃
┃承天寺 - 僧人(Seng ren)           天王殿 - 僧人(Seng ren)               ┃
┃学堂 - 欧阳詹(Ouyang zhan)                                              ┃
┃都督府 - 粮仓 - 施琅将军府 - 武将(Wu jiang) 官兵(Guan bing)             ┃
┃将军府 - 靖海侯 施琅(Shi lang)                                          ┃",me);
write("
┃城隍庙 - 庙祝(Miao zhu)                                                 ┃
┃杂货铺 - 杂货铺老板娘 陈阿婆(Chen apo)                                  ┃
┃甘露戒坛 - 少林派第三十八代弟子「辣手灭倭」慧金尊者(Hui jin)            ┃
┃济世堂老店 - 药铺掌柜 王通治(Wang tongzhi)                              ┃
┃药房 - 药铺小厮(Yaopu xiaosi)                                           ┃
┃中心广场 - 胡人(Hu ren) 捕头(Bu tou) 小贩(Xiao fan)                     ┃
┃望州亭 - 青城派第五代弟子 贾人达(Jia renda)                             ┃
┃千手岩 - 丐帮一袋弟子 赵狗儿(Zhao gouer)                                ┃
┃山路 - 采茶女(Girl)                                                     ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
return 1;
	}

  else if(arg == "foshan" || arg == "佛山")
  {
	  write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『佛山NPC方位图』                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃佛山林间道 - 张康(Zhang kang)            张朝唐(Zhang chaotang)         ┃
┃英雄典当 - 老朝奉(Lao chaofeng)                                         ┃
┃佛山镇街 - 家丁(Jia ding)                锺小二(Zhong xiaoer)           ┃
┃烧饼油条铺 - 王老汉(Wang laohan)                                        ┃
┃英雄楼 - 酒楼老板 凤七(Feng qi)                                         ┃
┃英雄楼 - 瘦商人(Shou shangren)        胖商人(Pang shangren)             ┃
┃英雄会馆 - 凤一鸣(Feng yiming)                                          ┃
┃麻溪铺 - 潇湘子(Xiaoxiang zi)                                           ┃
┃戚家大院 - 戚芳(Qi fang)                                                ┃
┃           连城派第五代弟子「铁锁横江」戚长发(Qi changfa)               ┃",me);
write("
┃茶亭 - 九个半门派总掌门 袁紫衣(Yuan ziyi)                               ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
return 1;
	}

  else if(arg =="hz" || arg == "杭州")
  {
	  write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『杭州NPC方位图』                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃南浔镇 - 庄允城(Zhuang yuncheng)                                        ┃
┃飞来峰 - 渤海帮帮主 洪胜海(Bangzhu) 渤海帮 帮众(Bangzhong)              ┃
┃灵隐寺 - 知客僧(Zhike seng)                                             ┃
┃大雄宝殿 - 枯木禅师(Kumu chanshi)                                       ┃
┃法净寺 - 法镜寺 - 小沙弥(Xiao shami)                                    ┃
┃法喜寺 - 老和尚(Seng ren)                                               ┃
┃玉泉书院 - 顾炎武(Gu yanwu)                                             ┃
┃保淑塔 - 天河帮帮主 黄伯流(Bangzhu) 天河帮 帮众(Bangzhong)              ┃
┃龙门镖局 - 都大锦(Du dajin)                                             ┃
┃小院 - 宁镖头(Ning biaotou)   周镖头(Zhou biaotou)                      ┃",me);
write("
┃小院 - 贾镖头(Jia biaotou)    林镖头(Lin biaotou)                       ┃
┃小院 - 翁镖头(Weng biaotou)   宋镖头(Song biaotou)                      ┃
┃铁匠铺 - 铁匠(Tie jiang) 欧治子(Ou zhizi)                               ┃
┃牛家村 - 杨铁心(Yang tiexin) 郭啸天(Guo xiaotian)                       ┃
┃酒店 - 酒店老板「跛子」曲三(Qu san)                                     ┃
┃海堤 - 塘工(Tanggong)                                                   ┃
┃盐田 - 海沙派盐枭(Yanxiao)                                              ┃
┃海神庙 - 天鹰教众(Tianying jiaozhong)                                   ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
return 1;
	}

	else if(arg == "jiax" || arg == "嘉兴")
	{
		write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『嘉兴NPC方位图』                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃太湖 - 归云庄少庄主 陆冠英(Lu guanying)                                 ┃
┃嘉兴南湖 - 「赤练仙子」李莫愁(Li mochou)                                ┃
┃烟雨楼 - 店小二(Xiao er) 御膳房总管 海老公(Hai laogong)                 ┃
┃         御膳房小太监 小桂子(Xiao guizi)                                ┃
┃大门 - 家丁(Jia ding)                                                   ┃
┃书房 - 归云庄主 陆乘风(Lu chengfeng)     书童(Shu tong)                 ┃
┃花厅 - 小兰(Xiao lan)                    小菊(Xiao ju)                  ┃
┃茶亭 -   日月神教右使「天王老子」向问天(Xiang wentian)                  ┃
┃梅庄前厅 - 梅庄家人「一字电剑」丁坚(Ding jian)                          ┃
┃           梅庄家人「五路神」施令威(Shi lingwei)                        ┃",me);
write("
┃梅庄大庄主 黄钟公(Huangzhong gong)                                      ┃
┃梅庄二庄主 黑白子(Heibai zi)                                            ┃
┃梅庄三庄主 秃笔翁(Tubi weng)                                            ┃
┃梅庄四庄主 丹青生(Danqing sheng)                                        ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
return 1;
	}

	else if(arg =="bt" || arg =="白驼")
	{
		write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『白驼NPC方位图』                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃大道 - 白驼山第四代弟子 家丁(Jiading)                                   ┃
┃小路 - 白驼山第四代弟子 婢女(Binu)                                      ┃
┃       白驼山庄武师 马光佐(Ma guangzuo)                                 ┃
┃小山丘 - 白驼山少庄主 欧阳克(Ouyang ke)                                 ┃
┃大厅 -  白衣舞姬(Baiyi wuji)                                            ┃
┃少主睡房 - 侍姬(Shi ji)                                                 ┃
┃灵蛇阁 - 白驼山庄庄主「西毒」欧阳锋(Ouyang feng)                        ┃
┃白驼山山门 -  白驼山庄账房先生 尹克西(Yin kexi)                         ┃
┃蛇场 -  白驼山庄 蛇奴(She nu)                                           ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫",me);
write("
┃疏勒 -  小克孜(Xiao kezi)            花帽摊贩 爱西翰(Aixihan)           ┃
┃艾提朵尔清真寺 -穆斯林(Moslem)       手艺工匠 再尔格尔(Zaier ger)       ┃
┃大巴扎 - 小克孜(Xiao kezi)           回族商人 阿密特(Amite)             ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
return 1;
}

	else if(arg =="xx" || arg =="星宿")
	{
		write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『星宿派NPC方位图』                        ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃日月洞 -  星宿派开山祖师「星宿老怪」丁春秋(Ding chunqiu)                ┃
┃银山道 -  星宿派第二代弟子「星宿派二师兄」狮吼子(Shihou zi)             ┃
┃          星宿派钹手(Boshou)                                            ┃
┃          星宿派号手(Haoshou)                                           ┃
┃          星宿派鼓手(Gushou)                                            ┃
┃星宿海 -  星宿派第二代弟子「星宿派三师兄」天狼子(Tianlang zi)           ┃
┃石道 -    星宿派第五代弟子「赛昆仑」采花子(Caihua zi)                   ┃
┃山口 -    乌老大(Wu laoda)                                              ┃
┃天山山路 - 星宿派第二代弟子「星宿派小师妹」阿紫(Azi)                    ┃
┃         - 采药人(Caiyao ren)                                           ┃",me);
write("
┃山洞 -    星宿派第二代弟子「星宿派大师兄」摘星子(Zhaixing zi)           ┃
┃高昌迷宫 - 「一指震江南」华辉(Hua hui)                                  ┃
┃小路 -    星宿派第二代弟子「星宿派八师兄」出尘子(Chuchen zi)            ┃
┃阿拉沟 -   锡伯少女(Girl)                                               ┃
┃冰川古道 -   波斯商人(Bosi shangren)                                    ┃
┃天山脚下 -  哈萨克(Hazakh)                                              ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃伊犁城 -  江湖术士(Shu shi)             维吾尔族妇女(Woman)             ┃
┃巴扎 -  杂货铺老板 买卖提(Maimaiti)                                     ┃
┃巴依家院 -  巴依 胡老爷(Hu laoye)       阿凡提(Afanti)                  ┃
┃赛马场 -  李文秀(Li wenxiu)                                             ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
return 1;
}

		else if(arg =="hs" || arg =="华山")
	{
		write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『华山及华山村NPC方位图』                  ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃私塾 - 老秀才(Lao xiucai)                                               ┃
┃小巷尽头 - 小流氓(Punk) 地痞(Dipi)                                      ┃
┃民房 - 翠花(Cui hua)                                                    ┃
┃小棚子 - 王小二(Wang xiaoer)                                            ┃
┃杂货店 - 小店老板 李四(Li si)                                           ┃
┃铁匠铺 - 冯铁匠(Feng)                                                   ┃
┃玉泉院 -  李铁嘴(Li tiezui)                                             ┃
┃民宅 - 地保(Dibao)                                                      ┃
┃草棚 - 小贩(Seller)                                                     ┃
┃青柯坪 - 游客(Youke) 江湖豪客(Jianghu haoke)                            ┃",me);
write("
┃玉女峰山路 - 华山派第十四代弟子 高根明(Gao genming)                     ┃
┃小山路 - 华山派第十四代弟子 施戴子(Shi daizi)                           ┃
┃华山小筑 - 华山派第十二代长老 高老者(Gao lao)                           ┃
┃           华山派第十二代长老 矮老者(Ai lao)                            ┃
┃练武场 - 华山派第十四代弟子 劳德诺(Lao denuo)                           ┃
┃客厅 - 华山派第十三代掌门「君子剑」岳不群(Yue buqun)                    ┃
┃东廊 - 华山派第十四代弟子 梁发(Liang fa)                                ┃
┃西廊 - 华山派第十四代弟子 岳灵姗(Yue lingshan)                          ┃
┃后院 - 华山派第十四代弟子「六猴儿」陆大有(Lu dayou)                     ┃
┃偏厅 - 华山派第十三代掌门夫人 宁中则(Ning zhongze)                      ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
return 1;
}
		else if(arg =="wud" ||arg =="武当")
		{
			write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『武当NPC方位图』                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃玄岳门 - 武当派第三代弟子 知客道长(Zhike daozhang)                      ┃
┃遇真宫 - 武当派第三代弟子 制香道长(Zhixiang daozhang)                   ┃
┃榔梅园 - 武当派第四代弟子「守园道长」成高道长(Chenggao daozhang)        ┃
┃南岩峰 - 武当派第二代弟子「武当七侠」莫声谷(Mo shenggu)                 ┃
┃朝天宫 - 武当派第三代弟子 清虚道长(Qingxu daozhang)                     ┃
┃三清殿 - 武当派第三代弟子 谷虚道长(Guxu daozhang)                       ┃
┃         武当派第二代弟子「武当首侠」宋远桥(Song yuanqiao)              ┃
┃藏经阁 - 武当派第五代弟子 道童(Daotong)                                 ┃
┃东厢走廊 - 武当派第二代弟子「武当四侠」张松溪(Zhang songxi)             ┃
┃茶室 - 武当派第五代弟子「伺茶道童」小翠(Cui)                            ┃",me);
write("
┃后院 - 武当派第二代弟子「武当二侠」俞莲舟(Yu lianzhou)                  ┃
┃林间小径 - 武当派第五代弟子 清风(Qingfeng)                              ┃
┃           武当派第五代弟子 明月(Mingyue)                               ┃
┃后山小院 - 武当派开山祖师「邋遢真人」张三丰(Zhang sanfeng)              ┃ 
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
		return 1;
		}
		else if(arg =="sl" || arg == "少林")
		{
			write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『少林NPC方位图』                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃少林寺 - 少林派第四十一代弟子「知客僧」虚明(Xu ming)                    ┃
┃         少林派第四十一代弟子「知客僧」虚通(Xu tong)                    ┃
┃广场 -   少林派第四十代弟子 清法比丘(Qingfa biqiu)                      ┃
┃         少林派第四十代弟子 清为比丘(Qingwei biqiu)                     ┃
┃         少林派第四十代弟子 清无比丘(Qingwu biqiu)                      ┃
┃监狱 -   少林派第四十代弟子 清缘比丘(Qingyuan biqiu)     狱卒(Yu zu)    ┃
┃广场 -   少林派第四十代弟子 清善比丘(Qingshan biqiu)                    ┃ 
┃鼓楼七层 - 少林派第四十代弟子 清闻比丘(Qingwen biqiu)                   ┃
┃钟楼七层 - 少林派第四十代弟子 清晓比丘(Qingxiao biqiu)                  ┃
┃茶室 -     少林派第四十代弟子 清乐比丘(Qingle biqiu)                    ┃",me);
write("
┃千佛殿 -   少林派第四十代弟子 清观比丘(Qingguan biqiu)                  ┃
┃戒律院 - 少林派第三十六代弟子「戒律院主持」玄痛大师(Xuantong dashi)     ┃ 
┃         执法僧兵(Seng bing)                                            ┃
┃山门殿 - 守寺僧兵(Seng bing)                                            ┃
┃方丈室 -  少林派第三十六代弟子「少林寺方丈」玄慈大师(Xuanci dashi)      ┃
┃般若五堂 -   少林派第三十六代弟子「般若堂首座」玄难大师(Xuannan dashi)  ┃
┃达摩院二楼 - 少林派第三十六代弟子「达摩院主持」玄悲大师(Xuanbei dashi)  ┃
┃罗汉五堂 -   少林派第三十六代弟子「罗汉堂首座」玄苦大师(Xuanku dashi)   ┃
┃天王殿 -     少林派第三十九代弟子 道果禅师(Daoguo chanshi)              ┃
┃大雄宝殿 -   少林派第三十九代弟子 道正禅师(Daozheng chanshi)            ┃
┃练武场 -     少林派第三十九代弟子 道觉禅师(Daojue chanshi)              ┃
┃走廊 -       少林派第三十九代弟子 道品禅师(Daopin chanshi)              ┃
┃藏经阁一楼 - 少林派第三十九代弟子 道一禅师(Daoyi chanshi)               ┃",me);
write("
┃             少林派第三十九代弟子 道相禅师(Daoxiang chanshi)            ┃
┃             少林派第三十九代弟子 道象禅师(Daoxiang chanshi)            ┃
┃             少林派第三十九代弟子 道尘禅师(Daochen chanshi)             ┃
┃             少林派第三十九代弟子 道成禅师(Daocheng chanshi)            ┃
┃般若一堂 - 少林派第三十七代弟子「伏虎罗汉」澄心(Chengxin luohan)        ┃
┃般若二堂 - 少林派第三十七代弟子「接引罗汉」澄意(Chengyi luohan)         ┃
┃般若三堂 - 少林派第三十七代弟子「金刚罗汉」澄思(Chengsi luohan)         ┃
┃般若四堂 - 少林派第三十七代弟子「功德罗汉」澄识(Chengshi luohan)        ┃
┃般若五堂 - 少林派第三十七代弟子「光明罗汉」澄志(Chengzhi luohan)        ┃
┃般若六堂 - 少林派第三十七代弟子「庄严罗汉」澄信(Chengxin luohan)        ┃
┃般若七堂 - 少林派第三十七代弟子「日月罗汉」澄灵(Chengling luohan)       ┃
┃般若八堂 - 少林派第三十七代弟子「须弥罗汉」澄欲(Chengyu luohan)         ┃
┃般若九堂 - 少林派第三十七代弟子「广力罗汉」澄尚(Chengshang luohan)      ┃",me);
write("
┃藏经阁二楼 -  少林派第三十八代弟子 慧真尊者(Huizhen zunzhe)             ┃
┃和尚院一部 -  少林派第三十八代弟子 慧合尊者(Huihe zunzhe)               ┃
┃和尚院二部 -  少林派第三十八代弟子 慧修尊者(Huixiu zunzhe)              ┃
┃和尚院三部 -  少林派第三十八代弟子 慧色尊者(Huise zunzhe)               ┃
┃和尚院四部 -  少林派第三十八代弟子 慧虚尊者(Huixu zunzhe)               ┃
┃和尚院五部 -  少林派第三十八代弟子 慧名尊者(Huiming zunzhe)             ┃
┃和尚院六部 -  少林派第三十八代弟子 慧洁尊者(Huijie zunzhe)              ┃
┃罗汉一堂 -  少林派第三十七代弟子「降龙罗汉」澄观(Chengguan luohan)      ┃
┃罗汉二堂 -  少林派第三十七代弟子「清净罗汉」澄知(Chengzhi luohan)       ┃
┃罗汉三堂 -  少林派第三十七代弟子「归真罗汉」澄明(Chengming luohan)      ┃
┃罗汉四堂 -  少林派第三十七代弟子「精进罗汉」澄净(Chengjing luohan)      ┃
┃罗汉五堂 -  少林派第三十七代弟子「旃檀罗汉」澄坚(Chengjian luohan)      ┃
┃罗汉六堂 -  少林派第三十七代弟子「贤善罗汉」澄行(Chengxing luohan)      ┃",me);
write("
┃罗汉七堂 -  少林派第三十七代弟子「智慧罗汉」澄寂(Chengji luohan)        ┃
┃罗汉八堂 -  少林派第三十七代弟子「妙音罗汉」澄灭(Chengmie luohan)       ┃
┃罗汉九堂 -  少林派第三十七代弟子「金身罗汉」澄和(Chenghe luohan)        ┃
┃精进场 - 少林派第三十八代弟子 慧空尊者(Huikong zunzhe)                  ┃
┃后殿 -   少林派第三十八代弟子 慧如尊者(Huiru zunzhe)                    ┃
┃方丈楼 - 少林派第三十七代弟子 知客僧(Zhike seng)                        ┃
┃钟楼一层 - 扫地僧(Saodi seng)                                           ┃
┃厨房 -     烧饭僧(Shaofan seng)                                         ┃
┃走廊 -     少林派第五十四代弟子 宝树(Baoshu)                            ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
		return 1;
		}

		else if(arg =="gb" || arg == "丐帮")
		{
			write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『丐帮NPC方位图』                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃南阳城 -丐帮二袋弟子 裘万家(Qiu wanjia)                                 ┃
┃树洞内部 -丐帮七袋弟子 左全(Zuo quan)                                   ┃
┃土地庙 - 丐帮九袋长老「掌棒龙头」鲁有脚(Lu youjiao)                     ┃
┃         丐帮九袋长老「掌钵龙头」彭有敬(Peng youjing)                   ┃
┃竹林小道 -  丐帮九袋长老「执法长老」简长老(Jian zhanglao)               ┃
┃林间小屋 -  丐帮第十七代帮主「九指神丐」洪七公(Hong qigong)             ┃
┃竹林小道 -  丐帮二袋弟子 小叫化(Beggar)                                 ┃
┃树洞下 -  丐帮九袋长老「传功长老」梁长老(Liang zhanglao)                ┃
┃谷场槐树边 -   丐帮七袋弟子 马俱为(Ma juwei)                            ┃
┃屋角边 -   丐帮七袋弟子 何不净(He bujing)                               ┃",me);
write("
┃沙丘小洞 -  丐帮八袋弟子 余洪兴(Yu hongxing)                            ┃
┃土匪窝边 -  丐帮八袋弟子 黎生(Li sheng)                                 ┃
┃暗道 -   丐帮四袋弟子 快活三(Kuaihuo san)                               ┃
┃井底密洞 -  丐帮三袋弟子 莫不收(Mo bushou)                              ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
		return 1;
		}

		else if(arg =="xi" || arg == "西夏")
		{
			write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『西夏NPC方位图』                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃林中大屋 -  「凶神恶煞」南海鳄神(Nanhai eshen)                          ┃
┃            「无恶不作」叶二娘(Ye erniang)                              ┃
┃西夏王陵 -  石人武士(Wu shi)                                            ┃
┃边门 -      皇宫卫士(Wei shi)                                           ┃
┃回廊 -      侍卫(Shi wei)     内侍(Nei shi)                             ┃
┃皇宫大门 -  皇宫卫士(Wei shi)                                           ┃
┃大将军府 -  校尉(Xiao wei)                                              ┃
┃骠骑营 -    西夏兵(Xixia bing)                                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃一品堂                                                                  ┃",me);
write("
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃          一品堂总管 努儿海(Nuerhai)                                    ┃
┃          一品堂武士(Wu shi)                                            ┃
┃          「穷凶极恶」云中鹤(Yun zhonghe)                               ┃
┃          征东大将军「西夏王爷」赫连铁树(Helian tieshu)                 ┃
┃石门 -    采石人(Caishi ren)                                            ┃
┃神鹰镖局 -  镇西北(Zhen xibei)                                          ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
return 1;
		}

		else if(arg == "gm" || arg == "古墓")
		{
			write("
┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
┃                             『古墓NPC方位图』                          ┃
┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫
┃後堂 -   古墓派第三代弟子「神雕侠侣」小龙女(Xiao longer)                ┃
┃         神雕大侠 杨过(Yang guo)                                        ┃
┃树林 -   古墓派第五代弟子 黄衣少女(Huangyi girl)                        ┃
┃         古墓派第五代弟子 白衣少女(baiyi girl)                          ┃
┃玉蜂房 - 古墓管家 孙婆婆(Sun popo)                                      ┃
┃厨房 -   小颦(Xiao pin)                                                 ┃
┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n",me);
           return 1;
		}
		else
		{
			return notify_fail("错误暗语，请使用 npc+NPC地区 查询\n");
		}
}
