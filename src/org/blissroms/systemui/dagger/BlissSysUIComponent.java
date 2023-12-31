/*
 * Copyright (c) 2014-2023 BlissRoms Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

package org.blissroms.systemui.dagger;

import com.android.systemui.dagger.DefaultComponentBinder;
import com.android.systemui.dagger.DependencyProvider;
import com.android.systemui.dagger.SysUIComponent;
import com.android.systemui.dagger.SysUISingleton;
import com.android.systemui.dagger.ReferenceSystemUIModule;
import com.android.systemui.dagger.SystemUICoreStartableModule;
import com.android.systemui.dagger.SystemUIModule;
import com.android.systemui.keyguard.CustomizationProvider;
import com.android.systemui.statusbar.NotificationInsetsModule;
import com.android.systemui.statusbar.QsFrameTranslateModule;

import org.blissroms.systemui.dagger.BlissSystemUIBinder;

import dagger.Subcomponent;

@SysUISingleton
@Subcomponent(modules = {
        DefaultComponentBinder.class,
        DependencyProvider.class,
        NotificationInsetsModule.class,
        QsFrameTranslateModule.class,
        SystemUIModule.class,
        SystemUICoreStartableModule.class,
        BlissSystemUIModule.class,
	BlissSystemUIBinder.class})
public interface BlissSysUIComponent extends SysUIComponent {
    @SysUISingleton
    @Subcomponent.Builder
    interface Builder extends SysUIComponent.Builder {
        BlissSysUIComponent build();
    }

    /**
     * Member injection into the supplied argument.
     */
    void inject(CustomizationProvider customizationProvider);
}
