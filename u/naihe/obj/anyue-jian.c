// 暗月之剑·奈何专用  anyue-jian.c
// by naihe  2002-04-26
// by naihe  2002-04-29 添加随机攻击力以及查看质地的函数。2002-05-12 添加两个杀人技法。
// 05-16 ，更改了判断方式，现在的暗月剑可说是3.1版吧！

#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void delete_obj();

int tempa,tempb,temp,
tempa = (random(200)),
tempb = (random(200));

void create()
{
        set_name(BLU"暗月之剑"NOR, ({ "anyue jian", "jian", "sword" }));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("long", "此剑不知由甚么质地造成(flip)，握着居然轻飘飘地感觉不到重量。剑柄上刻\n着几个极小的字：“"BLU"暗月之剑 往事如烟 嗜血无痕 御梦依然 --华山派·奈何"NOR"”\n");
                set("value", 0);
                set("no_steal", "这你也想偷？开玩笑罢。\n");
                set("rigidity", 200);
                set("shape", ({ "long", "sword" }) );
//              set("material", "steel"); // 不要这个“质地”。
                set("wield_msg", ""MAG"$N缓缓抽出"NOR"$n，"MAG"霎时间一阵寒气扑面而来。"NOR"\n"HIB"你顿时感到一阵阴森杀气！\n"NOR"" );
                set("unwield_msg", ""MAG"$N挽个剑花，将手中的"NOR"$n"MAG"插回了剑鞘。\n"NOR""HIB"一股无形的压力骤然消失，你不由得舒了口气。"NOR"\n");
	}
        if (tempa>tempb) temp=tempb;
        else temp=tempa;
        init_sword(1+temp);
        setup();
}

void init()
{
        add_action("do_wield", "wield");
        add_action("do_flip", "flip");
        add_action("do_aya", "aya");
        add_action("do_ayb", "ayb");
}

int do_wield(string arg)
{
        object me = this_player();

	if(arg=="anyue jian" || arg=="jian" || arg=="sword" || arg=="all")
	{
	        if(me->query("id") =="naihe" || me->query("id") =="spark" || wizardp(me))
		{
	                set("wield_msg", ""MAG"$N缓缓抽出"NOR"$n，"MAG"霎时间一阵寒气扑面而来。"NOR"\n"HIB"你顿时感到一阵阴森杀气！\n"NOR"" );
        	        set("unwield_msg", ""MAG"$N挽个剑花，将手中的"NOR"$n"MAG"插回了剑鞘。\n"NOR""HIB"一股无形的压力骤然消失，你不由得舒了口气。"NOR"\n");	
		        if (tempa>tempb) temp=tempb;
			        else temp=tempa;
	                set("rigidity", 200);
			init_sword(1+temp);
			return 0;
		}

		else
        	{
                	set("wield_msg", "$N缓缓抽出了$n握在手中。\n" );
	                set("unwield_msg", "$N将手中的$n插回了剑鞘。\n");
		        init_sword(1);
			temp=1;
	                delete("rigidity");
			call_out("delete_obj",3+random(5));
                	return 0;
	        }
	}
        return 0;
}

int do_flip(string arg)
{
        object me = this_player();

	if(!present("anyue jian",me)) return notify_fail("弯腰撅臀到地上去弹剑，姿势岂非太不雅观？！\n");

        if(!arg)
        {
                if(me->query("jing") < me->query("max_jing")/2)
                return notify_fail("你被"BLU"暗月之剑"NOR"寒气所逼，居然无法凝指弹下！\n");

                message_vision("$N轻扣中指往"BLU"暗月之剑"NOR"上一弹，只听得“叮”地一声清响，萦萦不绝。\n",me);
                if(me->query("id") == "naihe") write("攻击力为"+temp+"。\n");

                if(temp<15) write("这剑的质量甚差，甚至不知比不比得上寻常长剑。\n");
                if(temp>14 && temp<40) write("这把剑做工甚好，似乎要比平常刀剑略胜一筹。\n");
                if(temp>39 && temp<80) write("这把剑剑芒四射，一看就知道件利器！\n");
                if(temp>79 && temp<100) write("你只碰了它一下，居然发觉一阵寒气刹那间传遍了全身！这实在是把难得的宝剑！\n");
                if(temp>99 && temp<150) write("此剑寒气逼人，剑身上似乎隐隐有青光萦绕，天上人间，如此宝剑实在是极其罕有！\n");
                if(temp>149) write("此剑之犀利，已可与倚天、屠龙一较高下！\n");
                if(temp >= 200) write("此剑之完美，简直已到人类铸剑之术之极限！\n");

                message_vision("$N被"BLU"暗月之剑"NOR"寒气骤袭，险些喘不过气来。\n",me);
                me->set("jing",1);
                return 1;
        }
        return 0;
}

void delete_obj()
{
        message_vision(""HIB"\n一声幽幽的叹息不知从何处传来，只见"NOR""BLU"暗月之剑"NOR""HIB"剑身的光芒随即隐隐而退，终于整个消失不见。"NOR"\n",this_player());
        destruct(this_object());
}

// 暗月之剑之终极杀人技法
int do_aya(string arg)
{
        object me,ob;
        string whoa,whob;
	
        me=this_player();

// 若身上无剑，不通过。
	if(!present("anyue jian",me)) return notify_fail("剑在地上呢。\n");

// 若此时正在等待消失，不通过。
        if(this_object()->query("delete_obj") == 1) return 1;

// 若没有攻击目标，不通过。
        if(!arg) return notify_fail("格式：aya <id>\n");

// 若此剑未装备，不通过！
	if(!this_object()->query("equipped") )
		return notify_fail(""BLU"暗月之剑"NOR"并未出鞘！\n");

// 若此地无此人，不通过。
        ob=present(arg,environment(me));
        if(!ob) return notify_fail("这里没有这个生物。\n");     

// 若本人未在战斗状态，不通过；但在战斗状态的话，可以攻击任何人！
	if(!me->is_fighting()) return notify_fail("剑未嗜血，焉能通灵！\n");

// 若指定的是本人ID，不通过。
	if("arg"==me->query("id")) return notify_fail("唉，暗月之剑，岂是用来自杀之物！\n");

// 若想攻击奈何或闪烁，不通过。
        if(arg=="naihe" || arg=="spark") return notify_fail(""BLU"暗月之剑"NOR"灵气逼人，又怎会自伤其主？\n");

// 若本人非巫师、奈何或闪烁，不通过。
	if(me->query("id")!="naihe" && me->query("id")!="spark" && !wizardp(me))
		return notify_fail("你大声呼唤暗月之剑，它却不为所动。\n");

// 判断完毕，开始杀人了！！！
        whoa=(string)me->query("name");
        whob=(string)ob->query("name");

        tell_room(environment(me),""HIB"只听得"+whoa+"惨然一笑，叫道：“暗月之剑！难道你还不护主吗？！”"NOR"\n"HIR"只见"NOR""BLU"暗月之剑"NOR""HIR"从"+whoa+"手中激射而出，正中"+whob+"的心脏！"NOR"\n",({me,ob}));
        tell_object(ob,""HIR"只听得"+whoa+"一声惨笑，你眼前「唰」地划过一抹光影，"NOR""BLU"暗月之剑"NOR""HIR"已然插入你的胸膛！"NOR"\n");
        write(""HIB"你惨然一笑，叫道：“暗月之剑！难道你还不护主吗？！”"NOR"\n"HIR"只见暗月之剑从你手中激射而出，正中"+whob+"的心脏！"NOR"\n");
        ob -> set_temp("last_damage_from", "被"+whoa+"杀死了");
        ob -> die();

        set("delete_obj",1);
        call_out("delete_obj",3);
        me->start_busy(random(10));
        return 1;
}

void atk_backing()
{
        message_vision(""HIR"\n只见"NOR""BLU"暗月之剑"NOR""HIR"转了个圈，又飞回了$N的手中。"NOR"\n",this_player());
	this_object()->delete("attack_backing");
}

// 暗月之剑之投掷杀人技法
int do_ayb(string arg)
{
        object me,ob;
        string whoa,whob,can_do_it;
        int neili,melose,oblose,qi;

	me=this_player();
        neili=me->query("max_neili");

	if(!present("anyue jian",me)) return notify_fail("剑在地上呢。\n");
        if(!arg) return notify_fail("格式：aya <id>\n");
        if(this_object()->query("attack_backing") == 1) return notify_fail("剑还没飞回来呢。\n");
	if(!this_object()->query("equipped") )
		return notify_fail(""BLU"暗月之剑"NOR"并未出鞘！\n");
        ob=present(arg,environment(me));
        if(!ob) return notify_fail("这里没有这个生物。\n");     
	if(!me->is_fighting()) return notify_fail("剑未嗜血，焉能通灵！\n");
	if("arg"==me->query("id")) return notify_fail("唉，暗月之剑，岂是用来自杀之物！\n");
        if(arg=="naihe" || arg=="spark") return notify_fail(""BLU"暗月之剑"NOR"灵气逼人，又怎会自伤其主？\n");
	if(me->query("id")!="naihe" && me->query("id")!="spark" && !wizardp(me))
		return notify_fail("你大声呼唤暗月之剑，它却不为所动。\n");
        if(neili<100) return notify_fail("你没有足够的能力呼唤「暗月之剑」！\n");
        if((int)me->query("neili")<(neili*2/3)) return notify_fail("你已经没有足够的内力呼唤「暗月之剑」！\n");

        whoa=(string)me->query("name");
        whob=(string)ob->query("name"); 
        qi=ob->query("max_qi");

        tell_room(environment(me),""HIB"只听得"+whoa+"凄声叫道：“暗月之剑，嗜血无痕！”"NOR"\n"HIR"只见"NOR""BLU"暗月之剑"NOR""HIR"从"+whoa+"手中激射而出，直向"+whob+"飞去！\n"+whob+"堪堪躲过，却仍被剑气所伤！"NOR"\n",({me,ob}));
        tell_object(ob,""HIB"只听得"+whoa+"凄声叫道：“暗月之剑，嗜血无痕！”，一抹暗影向你激射而来！\n"NOR""HIR"你情急之下闪开身子，虽然堪堪避过，但剑气仍然对你造成了重创！"NOR"\n");
        write(""HIB"你凄声叫道：“暗月之剑，嗜血无痕！”"NOR"\n"HIR"只见"NOR""BLU"暗月之剑"NOR""HIR"从你手中激射而出，直向"+whob+"飞去！\n"+whob+"堪堪躲过，却仍被剑气所伤！"NOR"\n");

        melose=(neili/5+(random(neili/5)));
        if(melose>(int)me->query("neili")) melose=me->query("neili");
        oblose=(qi/4+(random(qi/2)));

        if(me->query("id")=="naihe") write("用掉"+melose+"点内力；造成"+oblose+"点伤害。\n");

        me->start_busy(5); // 忙时5秒！省得出现“剑飞出去了”，我还可以拿着剑劈人的情况……。
        me->add("neili",-melose);
        ob->add("qi",-oblose);

        set("attack_backing",1);
        call_out("atk_backing",3);	

        return 1; 
}
